<?php
session_start();
ini_set("log errors", 1);
ini_set('display errors', 1);
// Include config file
require_once "config.php";
 
// Define variables and initialize with empty values
$Dname = $Bdate = $Sex = $Relationship = "";
$Dname_err = $Bdate_err = $Sex_err = $Relationship_err = "";

if (isset($_GET["Dname"]) && !empty(trim($_GET["Dname"]))) {
	$_SESSION["Dname"] = $_GET["Dname"];
	$Dname = $_GET["Dname"];
	$Essn = $_SESSION["Ssn"];

	$sql1 = "SELECT * FROM DEPENDENT WHERE Essn = ? AND Dependent_name = ?";

	if($stmt1 = mysqli_prepare($link, $sql1)) {
		mysqli_stmt_bind_param($stmt1, "ss", $param_Essn, $param_Dname);
		$param_Essn = $Essn;
		$param_Dname = $Dname;

		if(mysqli_stmt_execute($stmt1)) {
			$result1 = mysqli_stmt_get_result($stmt1);
			if(mysqli_num_rows($result1) > 0) {
				$row = mysqli_fetch_array($result1);
				$Bdate = $row['Bdate'];
				$_SESSION["Bdate"] = $Bdate;
				$Relationship = $row['Relationship'];
				$_SESSION["Relationship"] = $Relationship;
				$Sex = $row['Sex'];
				$_SESSION["Sex"] = $Sex;
			}
		}
		
		mysqli_stmt_close($stmt1);
	}
}
 
// Processing form data when form is submitted
if($_SERVER["REQUEST_METHOD"] == "POST"){
    // Validate First name
    $Essn = $_SESSION["Ssn"];
    $Dname = trim($_POST["Dname"]);
    
    if(empty($Dname)){
        $Dname_err = "Please enter a name.";
    } elseif(!filter_var($Dname, FILTER_VALIDATE_REGEXP, array("options"=>array("regexp"=>"/^[a-zA-Z\s]+$/")))){
        $Dname_err = "Please enter a valid name.";
    } 
    // Validate Last name
    $Relationship = trim($_POST["Relationship"]);
    if(empty($Relationship)){
        $Relationship_err = "Please enter a Relatonship.";
    } elseif(!filter_var($Relationship, FILTER_VALIDATE_REGEXP, array("options"=>array("regexp"=>"/^[a-zA-Z\s]+$/")))){
        $Relationship_err = "Please enter a valid Relationship.";
    } 
 
	// Validate Sex
    $Sex = trim($_POST["Sex"]);
    if(empty($Sex)){
        $Sex_err = "Please enter Sex.";     
    }
	// Validate Birthdate
    $Bdate = trim($_POST["Bdate"]);

    if(empty($Bdate)){
        $Bdate_err = "Please enter birthdate.";     
    }	

    // Check input errors before inserting in database
    if(empty($Dname_err) && empty($Relationship_err) && empty($Bdate_err) 
				&& empty($Sex_err)){
        // Prepare an insert statement
        $sql = "UPDATE DEPENDENT
		SET Dependent_name = ?, Sex = ?, Bdate = ?, Relationship = ?
		WHERE Essn = ? AND Dependent_name = ?";
        if($stmt = mysqli_prepare($link, $sql)){
            // Bind variables to the prepared statement as parameters
            mysqli_stmt_bind_param($stmt, "ssssss", $param_NewDname, $param_Sex, $param_Bdate, $param_Relationship, $param_Essn, $param_OldDname);
            // Set parameters
	    $param_Essn = $Essn;
	    $param_NewDname = $Dname;
    	    $param_Sex = $Sex;
	    $param_Bdate = $Bdate;
            $param_Relationship = $Relationship;
	    $param_OldDname = $_SESSION["Dname"];
            
            // Attempt to execute the prepared statement
            if(mysqli_stmt_execute($stmt)){
                // Records created successfully. Redirect to landing page
				    header("location: viewDependents.php");
					exit();
            } else{
                echo "<center><h4>Error while updating Dependent</h4></center>";
				$SQL_err = mysqli_error($link);
				echo "<h3>SQL Errors ".$SQL_err."</h3>";
				$Dname_err = "Enter a unique Dependent's name.";
				$Dname = $_SESSION["Dname"];
            }
        }
         
        // Close statement
        mysqli_stmt_close($stmt);
    }

    // Close connection
    mysqli_close($link);
}
?>
 
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Update Dependent</title>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.css">
    <style type="text/css">
        .wrapper{
            width: 500px;
            margin: 0 auto;
        }
    </style>
</head>
<body>
    <div class="wrapper">
        <div class="container-fluid">
            <div class="row">
                <div class="col-md-12">
                    <div class="page-header">
                        <h2>Update a Dependent</h2>
			<h4>Employee SSN = <?php echo $Essn; ?> </h4>
                    </div>
                    <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>" method="post">
			<div class="form-group <?php echo (!empty($Dname_err)) ? 'has-error' : ''; ?>">
                            <label>Dependent's Name</label>
                            <input type="text" name="Dname" class="form-control" value="<?php echo $Dname; ?>">
                            <span class="help-block"><?php echo $Dname_err;?></span>
                        </div>
			<div class="form-group <?php echo (!empty($Relationship_err)) ? 'has-error' : ''; ?>">
                            <label>Relationship</label>
                            <input type="text" name="Relationship" class="form-control" value="<?php echo $Relationship; ?>">
                            <span class="help-block"><?php echo $Relationship_err;?></span>
                        </div>
			<div class="form-group <?php echo (!empty($Sex_err)) ? 'has-error' : ''; ?>">
                            <label>Sex</label>
                            <input type="text" name="Sex" class="form-control" value="<?php echo $Sex; ?>">
                            <span class="help-block"><?php echo $Sex_err;?></span>
                        </div>			                  
			<div class="form-group <?php echo (!empty($Bdate_err)) ? 'has-error' : ''; ?>">
                            <label>Birth date</label>
                            <input type="date" name="Bdate" class="form-control" value="<?php echo $Bdate; ?>">
                            <span class="help-block"><?php echo $Bdate_err;?></span>
                        </div>
                        <input type="submit" class="btn btn-primary" value="Submit">
                        <a href="viewDependents.php" class="btn btn-default">Cancel</a>
                    </form>
                </div>
            </div>        
        </div>
    </div>
</body>
</html>
