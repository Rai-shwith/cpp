import os
import html  # Import the html library for escaping text
from bs4 import BeautifulSoup
import re
# Root directory where your C++ labs are stored
ROOT_DIR = '.'  # Adjust if the script is not in the same directory
OUTPUT_FILE = 'index.html'

lab_container = """
            <div class="mb-8">
                <button
                    class="w-full text-left px-6 py-3 bg-gradient-to-r from-blue-500 to-blue-600 text-white font-semibold rounded-lg shadow-lg hover:bg-blue-600 focus:outline-none transition-colors"
                    onclick="toggleLab('{lab}')">
                    {lab}
                </button>
                <div id="{lab}" class="mt-4 hidden space-y-4">
                {lab_components}
                </div>
            </div>
"""

with open('index.html', 'r') as f:
    soup = BeautifulSoup(f, 'html.parser')
def get_cpp_files():
    cpp_files = {}
    # Traverse directories for C++ files
    for root, _, files in sorted(os.walk(ROOT_DIR),key=lambda x: x[0]):
        if 'LAB'  in root or 'Test Questions' in root:  # Limit to 'LAB' directories
            lab_name = os.path.basename(root)
            cpp_files[lab_name] = []
            for file in files:
                if file.endswith('.cpp'):
                    cpp_files[lab_name].append(os.path.join(root, file))
    return cpp_files

def get_lab_component(file_path,title,question,code,result):
    """This function gives the inner HTML required to fill the LAB components"""
    return f"""
        <div class="bg-white dark:bg-gray-800 p-6 rounded-lg shadow-lg transition-colors">
            <button class="w-full text-left font-semibold text-lg text-gray-800 dark:text-gray-100"
                onclick="toggleProgram('{file_path.replace("\\","/")}')">
                {title}
            </button>
            <div id="{file_path.replace("\\","/")}" class="mt-4 hidden">
                <p class="text-gray-600 dark:text-gray-400 mt-2"><strong>Question:</strong>{question}</p>
                <section class="mt-4">
                    <div class="flex justify-between">
                                    <h4 class="text-md font-semibold text-gray-700 dark:text-gray-300">
                                        Code:
                                    </h4>
                                    <button onclick="copyCode(event)" class="copy">
                                        <span data-text-end="Copied!" data-text-initial="Copy to clipboard"
                                            class="tooltip"></span>
                                        <span>
                                            <svg xml:space="preserve" style="enable-background:new 0 0 512 512"
                                                viewBox="0 0 6.35 6.35" y="0" x="0" height="20" width="20"
                                                xmlns:xlink="http://www.w3.org/1999/xlink" version="1.1"
                                                xmlns="http://www.w3.org/2000/svg" class="clipboard">
                                                <g>
                                                    <path fill="currentColor"
                                                        d="M2.43.265c-.3 0-.548.236-.573.53h-.328a.74.74 0 0 0-.735.734v3.822a.74.74 0 0 0 .735.734H4.82a.74.74 0 0 0 .735-.734V1.529a.74.74 0 0 0-.735-.735h-.328a.58.58 0 0 0-.573-.53zm0 .529h1.49c.032 0 .049.017.049.049v.431c0 .032-.017.049-.049.049H2.43c-.032 0-.05-.017-.05-.049V.843c0-.032.018-.05.05-.05zm-.901.53h.328c.026.292.274.528.573.528h1.49a.58.58 0 0 0 .573-.529h.328a.2.2 0 0 1 .206.206v3.822a.2.2 0 0 1-.206.205H1.53a.2.2 0 0 1-.206-.205V1.529a.2.2 0 0 1 .206-.206z">
                                                    </path>
                                                </g>
                                            </svg>
                                            <svg xml:space="preserve" style="enable-background:new 0 0 512 512"
                                                viewBox="0 0 24 24" y="0" x="0" height="18" width="18"
                                                xmlns:xlink="http://www.w3.org/1999/xlink" version="1.1"
                                                xmlns="http://www.w3.org/2000/svg" class="checkmark">
                                                <g>
                                                    <path data-original="#000000" fill="currentColor"
                                                        d="M9.707 19.121a.997.997 0 0 1-1.414 0l-5.646-5.647a1.5 1.5 0 0 1 0-2.121l.707-.707a1.5 1.5 0 0 1 2.121 0L9 14.171l9.525-9.525a1.5 1.5 0 0 1 2.121 0l.707.707a1.5 1.5 0 0 1 0 2.121z">
                                                    </path>
                                                </g>
                                            </svg>
                                        </span>
                                    </button>
                                </div>
                    <pre><code class="language-cpp">{code}</code></pre>
                </section>
                <div class="mt-4">
                    <h4 class="text-md font-semibold text-gray-700 dark:text-gray-300">Output:</h4>
                    <pre
                        class="bg-gray-900 text-green-400 overflow-x-auto p-3 rounded-md dark:bg-gray-700">{result}</pre>
                </div>
            </div>
        </div>

    """

def get_question_code_result(file_path):
    with open(file_path, 'r') as f:
        code = f.read()
        question_start = code.find('//')
        question_end = code.find('\n')
        question = code[question_start+2:question_end]
        result_start = code.find('/*\nOUTPUT:')
        result_end = code.find('*/')
        result = code[result_start+len('/*\nOUTPUT:'):result_end]
        code = code[question_end+1:result_start]
        escaped_code = html.escape(code)  # Escape special characters
        return (question,escaped_code,result)
    
def generate_title(file_path):
    title = os.path.basename(file_path)[:-4].replace('_',' ').title() # Remove '.cpp' extension , replace '_' with space and capitalize
    return title

def generate_html(cpp_files):
    # Loop through labs and files
    lab_box = soup.find(id='lab-container')
    lab_box.clear()
    for lab, files in cpp_files.items():
        programs = [] # store the inner HTML for each program
        for file_path in sorted(files, key=lambda x: int(re.search(r'\d+', os.path.basename(x)).group()) if re.search(r'\d+', os.path.basename(x)) else 0):
            title = generate_title(file_path=file_path)
            (question,code,result) = get_question_code_result(file_path=file_path)
            programs.append(get_lab_component(file_path=file_path,title=title,question=question,code=code,result=result))
        lab_component = ''.join(programs)
        lab_component = lab_container.format(lab=lab,lab_components=lab_component)
        lab_box.append(BeautifulSoup(lab_component, 'html.parser'))
    return soup.prettify()
            
def generate_readme(cpp_files):
    readme = """# CPP-DataStructures-2ndYear
Collection of Lab programs of my 2nd year C++ course
---
## Disclaimer 📌
Note: 
- These codes might differ slightly from those provided by the instructor, but they perform the intended tasks effectively. 
- Since our lab setup used Visual Studio 2010, you may notice 
    `#include <conio.h>` for `getch()` functions in some of the programs. 
    For newer compilers (like g++ on Linux), this inclusion isn't necessary and can be removed.
"""
    for lab, files in cpp_files.items():
        readme += f"\n---\n## {lab}\n"
        for file_path in files:
            title = generate_title(file_path=file_path)
            readme+= f"- [{title}]({file_path})\n"
    return readme

def main():
    cpp_files = get_cpp_files()
    html = generate_html(cpp_files)
    with open(OUTPUT_FILE, 'w',encoding="utf-8") as f:
        f.write(html)
    print(f"HTML file '{OUTPUT_FILE}' generated successfully!")
    readme = generate_readme(cpp_files)
    with open('README.md', 'w', encoding="utf-8") as f:
        f.write(readme)
    print("README.md generated successfully!")
        

if __name__ == "__main__":
    main()
