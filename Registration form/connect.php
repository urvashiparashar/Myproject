<?php
   
  $fname=$_POST['fname'];
  $lname=$_POST['lname'];
  $email=$_POST['email'];
  $phno=$_POST['phno'];
  $dob=$_POST['dob'];
  $reason=$_POST['reason']; 

  //database connection
  $conn=new mysqli('localhost','root','T@nnu2001','test');
  if($conn->connect_error)
  {
      die('connection failed: '.$conn->connect_error);

  }
  else{
      $stmt=$conn->prepare("insert into finalreg (fname,lname, email,phno,dob,reason) 
      values(?,?,?,?,?,?)");
      $stmt->bind_param("sssiss", $fname,$lname,$email,$phno,$dob,$reason);
      $stmt->execute();
     
      $stmt->close();
      $conn->close();
  }

?>

<a href="registration1.html"><button type="btn2" class="back" 
 style=" padding: 10px 30px;
    cursor: pointer;
    background: transparent;
    border: 0;
    outline: none;
    position: relative;
    margin-top: 280px;
    margin-left: 620px;
    transition: .5s;
    align-content: center;
    box-shadow: 0 0 20px 9px #1312121f;
    border-radius: 30px;
    background: linear-gradient(to right,#10ff1093,#dfe20d); "> GOBACK</a></button>
    <body >
      <h4>

      <center>Submit another response....<center></h4>
    </body>

