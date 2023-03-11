var alltwits = []
for(var i = 0; i < 8; i++) {
    var twit = document.getElementsByClassName("twit-text")
    var author = document.getElementsByClassName("twit-author")

    var twits = {
        "twit": twit[i].textContent,
        "author": author[i].textContent
    };

    alltwits.push(twits)
}

var button = document.getElementById("create-twit-button")
var backdrop =  document.getElementById("modal-backdrop")
var modal =  document.getElementById("create-twit-modal")
var cancel = document.getElementsByClassName("modal-cancel-button")[0]
var closeButton = document.getElementsByClassName("modal-close-button")[0]
var createTwit = document.getElementsByClassName("modal-accept-button")[0]
var container = document.getElementsByClassName("twit-container")[0]
var searching = document.getElementById("navbar-search-button")
var searchBar = document.getElementById("navbar-search-input")
var unitwit = document.getElementsByClassName("twit")

button.addEventListener('click', function () {
    backdrop.classList.remove("hidden")
    modal.classList.remove("hidden")
})

closeButton.addEventListener('click', function () {
    backdrop.classList.add("hidden")
    modal.classList.add("hidden")
})

cancel.addEventListener('click', function () {
    backdrop.classList.add("hidden")
    modal.classList.add("hidden")
})

createTwit.addEventListener('click', function() {
    var twit = document.getElementById("twit-text-input").value 
    var author = document.getElementById("twit-attribution-input").value

    if(document.getElementById("twit-text-input").value === "") {
        alert("Cannot create twit without a twit")
    } else if(document.getElementById("twit-attribution-input").value === "") {
        alert("Cannot create twit without an author")
    } else {
        backdrop.classList.add("hidden")
        modal.classList.add("hidden")
        addTwit(twit, author)
        
        document.getElementById("twit-text-input").value = ""
        document.getElementById("twit-attribution-input").value = ""

        var newTwit = {
            "twit": twit,
            "author": author
        };
    
        alltwits.push(newTwit)
    }
})

searchBar.addEventListener("input", searchTwits)

searching.addEventListener("click", searchTwits)

function addTwit(twit, author) {
    var twitArticle = document.createElement("article")
    twitArticle.classList.add("twit")
    container.appendChild(twitArticle)
    

    var icon = document.createElement("div")
    icon.classList.add("twit-icon")
    twitArticle.appendChild(icon)

    var img = document.createElement("i")
    img.classList.add("fas")
    img.classList.add("fa-bullhorn")
    icon.appendChild(img)

    var content = document.createElement("div")
    content.classList.add("twit-content")
    twitArticle.appendChild(content)

    var p1 = document.createElement("p")
    p1.classList.add("twit-text")
    p1.textContent = twit

    var a = document.createElement("a")
    a.href = "#"
    a.textContent = author

    var p2 = document.createElement("p")
    p2.classList.add("twit-author")
    p2.appendChild(a)

    content.appendChild(p1)
    content.appendChild(p2)
}

function removeTwit(moreTwits) {
    moreTwits.remove()
}

function searchTwits() {
    while(unitwit.length > 0) {
        container.removeChild(unitwit[0])
    }

    alltwits.forEach(function(element) {
        if(element.twit.toLowerCase().includes(searchBar.value) || element.author.toLowerCase().includes(searchBar.value)) {
            addTwit(element.twit, element.author)
        }
    })
}