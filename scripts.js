const inputField1 = document.getElementById('first');
const inputField2cument.getElementById('second');
const addButton = document.getElementById('Btn');
const resultArea = document.getElementById('state');

addButton.addEventListener('click', () => {
    
    // 1. Get the values (they are strings at this point)
    const value1String = inputField1.value;
    const value2String = inputField2.value;

    // 2. CONVERT to Integers (Numbers)
    // We use parseInt() to ensure they are treated as whole numbers.
    const number1 = parseInt(value1String, 10); // The '10' ensures base-10
    const number2 = parseInt(value2String, 10);
    
    // OPTIONAL ALTERNATIVE for conversion:
    // const number1 = Number(value1String);
    // const number2 = Number(value2String);

    // 3. Perform the mathematical addition
    const sum = number1 + number2;

    // 4. Print the result back to the HTML
    resultArea.textContent = 'Total: ' + sum; 

    // console.log("The sum is:", sum);
});