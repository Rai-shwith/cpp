import os
import html  # Import the html library for escaping text
from bs4 import BeautifulSoup

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
    for root, _, files in os.walk(ROOT_DIR):
        if 'LAB' in root:  # Limit to 'LAB' directories
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
                onclick="toggleProgram('{file_path}')">
                {title}
            </button>
            <div id="{file_path}" class="mt-4 hidden">
                <p class="text-gray-600 dark:text-gray-400 mt-2"><strong>Question:</strong>{question}</p>
                <div class="mt-4">
                    <h4 class="text-md font-semibold text-gray-700 dark:text-gray-300">Code:</h4>
                    <pre><code class="language-cpp">{code}</code></pre>
                </div>
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
        for file_path in files:
            title = generate_title(file_path=file_path)
            (question,code,result) = get_question_code_result(file_path=file_path)
            programs.append(get_lab_component(file_path=file_path,title=title,question=question,code=code,result=result))
        lab_component = ''.join(programs)
        lab_component = lab_container.format(lab=lab,lab_components=lab_component)
        lab_box.append(BeautifulSoup(lab_component, 'html.parser'))
    return soup.prettify()
            

def main():
    cpp_files = get_cpp_files()
    html = generate_html(cpp_files)
    
    with open(OUTPUT_FILE, 'w') as f:
        f.write(html)
        
    print(f"HTML file '{OUTPUT_FILE}' generated successfully!")

if __name__ == "__main__":
    main()
