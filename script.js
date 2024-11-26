// Initialize code highlighting
document.addEventListener("DOMContentLoaded", () => {
    hljs.highlightAll();
});

// Toggle visibility of lab sections
function toggleLab(labId) {
    const lab = document.getElementById(labId);
    lab.classList.toggle("hidden");
}

// Toggle visibility of program sections within a lab
function toggleProgram(programId) {
    const program = document.getElementById(programId);
    program.classList.toggle("hidden");
}
function unescapeHTML(str) {
    const textArea = document.createElement('textarea');
    textArea.innerHTML = str;
    return textArea.value;
}
function getParent(element, tagName) {
    while (element.tagName !== tagName) {
        element = element.parentElement;
    }
    return element;
}
function copyCode(e) {
    console.log("Entering copyCode")
    const codeSection = getParent(e.target.parentElement, 'SECTION');
    let code = codeSection.querySelector('code').innerText;
    code = unescapeHTML(code);
    // Use the Clipboard API to copy the text
    navigator.clipboard.writeText(code).then(() => {
        console.log("Text copied to clipboard");
    }).catch((err) => {
        console.error("Failed to copy text: ", err);
    });
}
// Funtion to handle Disclaimer Pop-up
function handleDisclaimer() {
    // check weather disclaimer is already accepted or not
    const disclaimerAccepted = localStorage.getItem('disclaimerAccepted');
    if (disclaimerAccepted) {
        return;
    }
    const disclaimer = document.getElementById('disclaimer-popup');
    const acceptButton = document.getElementById('accept-disclaimer');
    disclaimer.classList.remove('hidden');
    acceptButton.addEventListener('click', () => {
        disclaimer.classList.add('hidden');
        localStorage.setItem('disclaimerAccepted', true);
    }
    );
}

handleDisclaimer();