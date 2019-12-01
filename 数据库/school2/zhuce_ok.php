<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>注册操作</title>
</head>

<body>
<?php
// 数据库连接
include'conn.php';
$a_name=$_POST['a_name'];
$a_password=$_POST['a_password'];
 
//执行UPDATE语句
$sql = "insert into admin (a_name,a_password) values ('".$a_name."','".$a_password."') ";
$result = mysqli_query($con,$sql); 
$err = mysqli_error($con);
if($err){
  /*echo"<script>alert('注册失败,请检查信息无误！'); location.href='zhuce.php';</script>";*/
}else{
  echo"<script>alert('注册成功'); location.href='login.php';</script>"; 
} 
//关闭数据库连接
mysqli_close($con);
?>
</body>
</html>