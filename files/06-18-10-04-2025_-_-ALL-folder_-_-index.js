const numberInput = document.getElementById('numberInput');
const inputContainer = document.getElementById('inputContainer');
const submitBtn = document.getElementById('submitBtn');

// Event listener for generating input fields based on user input
numberInput.addEventListener('input', function () {
    const numberOfFields = parseInt(this.value);

    // Clear the container before adding new input fields
    inputContainer.innerHTML = '';

    // Generate the specified number of input fields
    if (!isNaN(numberOfFields) && numberOfFields > 0) {
        for (let i = 0; i < numberOfFields; i++) {
            const inputField = document.createElement('input');
            inputField.type = 'number';
            inputField.classList.add('element-input');
            inputField.placeholder = `Input ${i + 1}`;
            inputContainer.appendChild(inputField);
        }
    }    
});

// Collect input values and navigate to selectionsort.html
submitBtn.addEventListener('click', function () {
    const inputFields = document.querySelectorAll('.element-input');
    const elements = []; // Initialize a new array to collect values

    // Collect the values from the input fields
    inputFields.forEach(field => {
        const value = field.value;
        if (!isNaN(value) && value.trim() !== '') {
            elements.push(parseInt(value));
        }
    });

    // Check if elements were collected and proceed
    if (elements.length > 0) {
        // Save the elements array to localStorage
        localStorage.setItem('elements', JSON.stringify(elements));
        // Redirect to the selection sort page
        window.location.href = 'selectionsort.html';
    } else {
        alert('Please enter valid numbers in all fields');
    }
});
