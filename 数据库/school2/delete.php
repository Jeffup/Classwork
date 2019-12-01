<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>执行删除操作</title>
</head>

<body>
<?php 
// 数据库连接
include'conn.php';
include'conn2.php';
$s_id = $_REQUEST["s_id"];

//2 执行SQL语句： 
$sql = " delete from student where s_id= " . $s_id;
$result = mysqli_query($con,$sql); 
$err = mysqli_error($con);
if($err){
  echo"<script>alert('删除失败'); location.href='index.php';</script>";
}else{
  echo"<script>alert('删除成功'); location.href='index.php';</script>"; 
} 
//关闭数据库连接
mysqli_close($con);
?>
 

</body>
</html>