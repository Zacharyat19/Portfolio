/*
 * Write your routing code in this file.  Make sure to add your name and
 * @oregonstate.edu email address below.
 *
 * Name: Zach Taylor
 * Email: taylzach@oregonsate.edu
 */

var path = require('path');
var express = require('express');
var twits = require("./twitData.json");
var exphbs = require("express-handlebars");
const { nextTick } = require('process');


var app = express();
var port = process.env.PORT || 3000;

app.engine("handlebars", exphbs({ defaultLayout: "Main" }))
app.set("view engine", "handlebars")

app.use(express.static('public'));

app.get('/', function (req, res) {
  res.status(200).render("page", {
    twits
  })
});

app.get('/twits/:n', function (req, res, next) {
  var n = req.params.n
  n = parseInt(n, 10)
  if(Number.isInteger(n)) {
    if((n >= 0) && (n <= 7)) {
      res.status(200).render("single", twits[n])
    } else {
      next()
    }
  } else {
    next()
  }
});

app.get('*', function (req, res) {
  res.status(404).render("404", {})
});

app.listen(port, function () {
  console.log("== Server is listening on port", port);
});
