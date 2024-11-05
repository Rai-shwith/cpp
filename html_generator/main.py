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

def generate_html(cpp_files):
    html_content = """
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.3.1/styles/default.min.css">
<script src="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.3.1/highlight.min.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.3.1/languages/cpp.min.js"></script>
<script>hljs.highlightAll();</script>
<title>C++ Data Structures Lab Programs</title>
    <style>
        body { font-family: Arial, sans-serif; margin: 20px; }
        h1 { color: #333; }
        h2 { color: #555; }
        pre { background-color: #f4f4f4; padding: 10px; border: 1px solid #ddd; overflow-x: auto; }
        .file { margin-bottom: 20px; }
    </style>
</head>
<body>
    <h1>C++ Data Structures Lab Programs</h1>
    <p><em>Note: These codes may differ slightly from those provided by the instructor, but they perform the intended tasks. `conio.h` was used for compatibility with Visual Studio 2010.</em></p>
"""

    # Loop through labs and files
    for lab, files in cpp_files.items():
        html_content += f"<h2>{lab}</h2>\n"
        for file_path in files:
            file_name = os.path.basename(file_path)
            html_content += f"<div class='file'><h3>{file_name}</h3>\n"
            
            # Read and escape the file content
            with open(file_path, 'r') as f:
                code = f.read()
                escaped_code = html.escape(code)  # Escape special characters
            
            # Add escaped code block
            html_content += f"<pre><code class=\"language-cpp\">{escaped_code}</code></pre></div>\n"

    # Close HTML tags
    html_content += """
<script src="https://{{cdn}}/prismjs@v1.x/components/prism-core.min.js"></script>
	<script src="https://{{cdn}}/prismjs@v1.x/plugins/autoloader/prism-autoloader.min.js"></script>
</body>
</html>
"""
    return html_content

def main():
    cpp_files = get_cpp_files()
    html_content = generate_html(cpp_files)
    
    # Write to index.html
    with open(OUTPUT_FILE, 'w') as f:
        f.write(html_content)
    
    print(f"HTML file '{OUTPUT_FILE}' generated successfully!")

if __name__ == "__main__":
    main()
