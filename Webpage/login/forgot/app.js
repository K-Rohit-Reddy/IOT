document.getElementById('forgotPasswordForm').addEventListener('submit', function(event) {
    event.preventDefault();

    const username = this.elements["username"].value;
    const newPassword = this.elements["newPassword"].value;
    const confirmPassword = this.elements["confirmPassword"].value;
    const resetMsg = document.getElementById('error-msg'); 
    const storedUsername = localStorage.getItem('username'); 
    const storedPassword = localStorage.getItem('password'); 

    if (username === storedUsername) {
        if (newPassword === confirmPassword) {

            localStorage.setItem('password', newPassword);
            resetMsg.innerText = "Password reset successfully!";
            resetMsg.style.color = "green";
        } else {
            resetMsg.innerText = "New Password and Confirm Password do not match.";
            resetMsg.style.color = "red";
        }
    } else {
        resetMsg.innerText = "Username not found.";
        resetMsg.style.color = "red";
    }
});
