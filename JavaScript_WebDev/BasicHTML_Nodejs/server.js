/*
 * Write your server code in this file.  Don't forget to add your name and
 * @oregonstate.edu email address below, so we know whose code we're grading.
 *
 * name: Zach Taylor
 * email: taylzach@oregonstate.edu
 */
 
var fs = require("fs")
var http = require("http")
var port = 3000
var html = ""
var css = ""
var js = ""
var htmlErr = ""

var htmlRead = fs.readFile("./public/index.html", "utf8", function(err, data) {
    if(err) {
        throw err
    }
    console.log("no error in html")
    html = data
})
console.log("done reading html")

var cssRead = fs.readFile("./public/style.css", "utf8", function(err, data) {
    if(err) {
        throw err
    }
    console.log("no error in css")
    css = data
})
console.log("done reading css")

var jsRead = fs.readFile("./public/index.js", "utf8", function(err, data) {
    if(err) {
        throw err
    }
    console.log("no error in js")
    js = data
})
console.log("done reading js")

var htmlErrRead = fs.readFile("./public/404.html", "utf8", function(err, data) {
    if(err) {
        throw err
    }
    console.log("no error in 404")
    htmlErr = data
})
console.log("done reading htmlErr")

var server = http.createServer(function(req, res) {
    if(req.url === "/index.html") {
        res.statusCode = 200
        res.setHeader("Content-Type", "text/html")
        res.write(html)
        res.end()
    } else if(req.url === "/style.css") {
        res.statusCode = 200
        res.setHeader("Content-Type", "text/css")
        res.write(css)
        res.end()
    } else if(req.url === "/index.js") {
        res.statusCode = 200
        res.setHeader("Content-Type", "application/javascript")
        res.write(js)
        res.end()
    } else if(req.url === "/404.html") {
        res.statusCode = 404
        res.setHeader("Content-Type", "text/html")
        res.write(htmlErr)
        res.end()
    } else if(req.url === "/") {
        res.statusCode = 200
        res.setHeader("Content-Type", "text/html")
        res.write(html)
        res.end()
    } else {
        res.statusCode = 404
        res.setHeader("Content-Type", "text/html")
        res.write(htmlErr)
        res.end()
    }
})

server.listen(port, function() {
    console.log("server is listening on:", port)
})