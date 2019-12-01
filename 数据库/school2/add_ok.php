<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>添加成功</title>
</head>

<body>
<?php
// 数据库连接
include'conn.php';
include'conn2.php';
$s_id=$_POST['s_id'];
$s_name=$_POST['s_name'];
$s_sex=$_POST['s_sex'];
$s_class=$_POST['s_class'];
$s_phone=$_POST['s_phone'];
//执行UPDATE语句
$sql = "insert into student values ('".$s_id."','".$s_name."','".$s_sex."','".$s_class."','".$s_phone."') ";
$result = mysqli_query($con,$sql); 
$err = mysqli_error($con);
if($err){
  echo"<script>alert('添加失败,请检查信息无误！'); location.href='add.php';</script>";
}else{
  echo"<script>alert('添加成功'); location.href='index.php';</script>"; 
} 
//关闭数据库连接
mysqli_close($con);
?>

</body>
</html>