import os
import html  # Import the html library for escaping text
from bs4 import BeautifulSoup

# Root directory where your C++ labs are stored
ROOT_DIR = '.'  # Adjust if the script is not in the same directory
OUTPUT_FILE = 'index.html'

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

def get_question_code_result(file_path):
    # Read and escape the file content
    with open(file_path, 'r') as f:
        code = f.read()
        escaped_code = html.escape(code)  # Escape special characters
        return escaped_code
    
def generate_title(file_path):
    title = os.path.basename(file_path)[:-4].replace('_',' ').title() # Remove '.cpp' extension , replace '_' with space and capitalize
    return title

def generate_html(cpp_files):
    # Loop through labs and files
    for lab, files in cpp_files.items():
        for file_path in files:
            title = generate_title(file_path=file_path)
            

def main():
    cpp_files = get_cpp_files()
    generate_html(cpp_files)
    
    print(f"HTML file '{OUTPUT_FILE}' generated successfully!")

if __name__ == "__main__":
    main()
