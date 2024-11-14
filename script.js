// Script for toggling visibility of files within each lab
function toggleLab(labHeader) {
    const files = labHeader.nextElementSibling;
    if (files.classList.contains('hidden')) {
        files.classList.remove('hidden');
        labHeader.innerHTML = labHeader.innerHTML.replace('➤', '▼');
    } else {
        files.classList.add('hidden');
        labHeader.innerHTML = labHeader.innerHTML.replace('▼', '➤');
    }
}
