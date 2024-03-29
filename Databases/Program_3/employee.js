module.exports = function(){
    var express = require('express');
    var router = express.Router();

    function getProjects(res, mysql, context, complete){
	mysql.pool.query('SELECT Pnumber, Pname FROM PROJECT', function(error, results, fields) {
		if(error) {
			res.write(JSON.stringify(error));
			res.end;
		}
		context.projects = results;
		complete();
	});
    }

    function getEmployees(res, mysql, context, complete){
	mysql.pool.query("SELECT Fname, Lname, Salary, Dno FROM EMPLOYEE", function(error, results, fields){
            if(error){
                res.write(JSON.stringify(error));
                res.end();
            }
            context.employee = results;
            complete();
        });
    }

    function getEmployeeByProject(req, res, mysql, context, complete){
      var query = "SELECT Fname, Lname, Salary, Dno FROM WORKS_ON, EMPLOYEE WHERE WORKS_ON.Essn = EMPLOYEE.Ssn AND WORKS_ON.Pno = ?";
      console.log(req.params)
      var inserts = [req.params.project]
      mysql.pool.query(query, inserts, function(error, results, fields){
            if(error){
                res.write(JSON.stringify(error));
                res.end();
            }
            context.employee = results;
	    context.PNO = req.params.project;
            //complete();
        });

	var sql2 = "SELECT Pname, Plocation FROM PROJECT WHERE Pnumber = ?";
	console.log(req.params)
	var inserts2 = [req.params.project];
	mysql.pool.query(sql2, inserts2, function(error, results2, fields) {
		if(error) {
			res.write(JSON.stringify(error));
			res.end;
		}
		if(results2[0]) {
			context.Pname = results2[0].Pname;
			context.Plocation = results2[0].Plocation;
		} else {
			context.Pname = "Does NOT EXIST";
			context.Plocation = "NO WHERE";
		}
		complete();
	});
    }

    function getEmployeeWithNameLike(req, res, mysql, context, complete){
        var query = "SELECT Fname, Lname, Salary, Dno FROM EMPLOYEE WHERE Fname LIKE " + mysql.pool.escape(req.params.s + '%');
	console.log(query);
        
        mysql.pool.query(query, function(error, results, fields){
            if(error){
                res.write(JSON.stringify(error));
                res.end();
            }
            context.employee = results;
	    context.SEARCH = mysql.pool.escape(req.params.s);
            complete();
        });
    }

    router.get('/', function(req, res){
        var callbackCount = 0;
        var context = {};
        context.jsscripts = ["filterEmployee.js","searchEmployee.js"];
        var mysql = req.app.get('mysql');
        getEmployees(res, mysql, context, complete);
        getProjects(res, mysql, context, complete);
        function complete(){
            callbackCount++;
            if(callbackCount >= 2){
                res.render('employee', context);
            }

        }
    });

    router.get('/filter/:project', function(req, res){
        var callbackCount = 0;
        var context = {};
     	context.jsscripts = ["filterEmployee.js","searchEmployee.js"];
        var mysql = req.app.get('mysql');
        getEmployeeByProject(req,res, mysql, context, complete);
        getProjects(res, mysql, context, complete);
        function complete(){
            callbackCount++;
            if(callbackCount >= 2){
                res.render('employee', context);
            }

        }
    });

    router.get('/search/:s', function(req, res){
        var callbackCount = 0;
        var context = {};
        context.jsscripts = ["filterEmployee.js","searchEmployee.js"];
        var mysql = req.app.get('mysql');
        getEmployeeWithNameLike(req, res, mysql, context, complete);
        getProjects(res, mysql, context, complete);
        function complete(){
            callbackCount++;
            if(callbackCount >= 2){
                res.render('employee', context);
            }
        }
    });

  router.get('/search/', function(req, res) {
	var callbackCount = 0;
	var context = {};
	context.jsscripts = ["filterEmployee.js", "searchEmployee.js"];
	var mysql = req.app.get('mysql');
	getEmployees(res, mysql, context, complete);
	getProjects(res, mysql, context, complete);
	function complete() {
		callbackCount ++;
		if(callbackCount >= 2) {
			res.render('employee', context);
		}
	}
  });
  return router;
}();
