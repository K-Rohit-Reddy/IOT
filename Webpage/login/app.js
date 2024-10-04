const form = document.getElementById("loginForm");
const errorMsg = document.getElementById("error-msg");

function validateCredentials(inputUsername, inputPassword) {
    const storedUsername = localStorage.getItem('username');
    const storedPassword = localStorage.getItem('password');

    if (storedUsername !== inputUsername || storedPassword !== inputPassword) {
        if (storedUsername !== inputUsername && storedPassword !== inputPassword) {
            errorMsg.innerText = "Sorry, your Username and Password were incorrect.";
        } else if (storedUsername !== inputUsername) {
            errorMsg.innerText = "Sorry, your Username was incorrect.";
        } else {
            errorMsg.innerText = "Sorry, your Password was incorrect.";
        }
    } else {
        window.location.href = "/dashboard/dashboard.html";
    }
}

form.addEventListener("submit", (event) => {
    event.preventDefault();
    const inputUsername = form.elements["username"].value;
    const inputPassword = form.elements["password"].value;
    validateCredentials(inputUsername, inputPassword);
});
