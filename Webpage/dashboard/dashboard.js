// Toggle the navbar menu on small screens
function toggleMenu() {
    var navLinks = document.querySelector("#navLinks");
    navLinks.classList.toggle("show");
}

// Handle appliance switch toggles and update status badges accordingly
let inputs = document.querySelectorAll(".appliance-card input[type='checkbox']");
for (let input of inputs) {
    input.addEventListener("change", (event) => {
        let statusBadge = event.target.closest(".card-body").querySelector(".card-text .badge");
        if (event.target.checked) {
            statusBadge.textContent = "On";
            statusBadge.classList.remove("bg-danger");
            statusBadge.classList.add("bg-success");
        } else {
            statusBadge.textContent = "Off";
            statusBadge.classList.remove("bg-success");
            statusBadge.classList.add("bg-danger");
        }
    });
}
