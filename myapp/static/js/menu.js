document.addEventListener("DOMContentLoaded", function () {
    const toggle = document.getElementById("menu-toggle");
    const menu = document.getElementById("nav-menu");

    toggle.addEventListener("click", function () {
        menu.classList.toggle("open");
    });
});