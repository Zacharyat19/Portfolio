var mysql = require('mysql');
var pool = mysql.createPool({
  connectionLimit : 10,
  host            : 'classmysql.engr.oregonstate.edu',
  user            : 'cs340_taylzach',
  password        : '',
  database        : 'cs340_taylzach'
});
module.exports.pool = pool;
