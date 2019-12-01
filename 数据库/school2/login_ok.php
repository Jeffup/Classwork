<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>登录操作</title>
</head>
<?php

if(isset ($_GET['out']))
    {
	setcookie('a_name',"",time()-3600);
	echo"<script>alert('注销成功^_^');location.href='login.php'; </script>";
	}
if($_POST['a_name']&&$_POST['a_password'])
    {
	$coon=new mysqli("localhost","root","root","school");
    if($coon->connect_error){	
	  die("连接失败:".$coon->connect_error);
	  }else{
	  $strSQL= "select * from admin where a_name='".$_POST['a_name']."' and a_password='".$_POST['a_password']."'";
	  //echo $strSQL."<br>";//测试语句	  
	  $rs=$coon->query($strSQL);
	 // echo $rs->num_rows;//测试语句	  
	  if($rs->num_rows>0){
		setcookie('a_name',$_POST['a_name'],time()+3600);
		session_start();
        echo "<script>location.href='index.php';</script>"; 
		}else{
	    echo "<script>alert('用户名或密码错误');location.href='login.php';</script>";
		}		  
      }
  
				  
	}else{
		 echo "<script>alert('用户名或密码为空');location.href='login.php';</script>";
		}


?>
<body>
</body>
</html>