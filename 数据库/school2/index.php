<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<link rel="stylesheet" href="../css/install.css" />
<title>信息列表</title>
</head>
<body>
 
<?php 
include'conn.php';
include'conn2.php';
include'page.php';

 
$sql = "select * from student ";
$data=mysqli_query($con,$sql);
$rows=mysqli_num_rows($data);
Page($rows,10); 
$sql2 = "select * from student order by s_id asc limit $select_from $select_limit";//获取分页数据
$result=mysqli_query($con,$sql2);
?>
<br/>
<div class="wrap">
  <div class="section">
    <div class="step">
<table align="center" width="750px" border="0" bgcolor="#FFFFFF">
<tr>
      <ul>    
        <li class="current" align='center'><em>✿</em>学生信息管理</li>    
      </ul>
<tr>
</div>

<td colspan="7" height="30">
<form action="search.php" method="get">
<input type="text" name="search"  /> <input type="submit" value="搜索" />
</form>
<div class="server">
</td>
</tr>
<tr>
<td class="td1">序号</td>
<td class="td1">学号</td>
<td class="td1">姓名</td>
<td class="td1">性别</td>
<td class="td1">班级</td>
<td class="td1">手机</td>
<td class="td1">操作</td>
</tr>
<?php
$num=1;//序号
while($row=mysqli_fetch_array($result)){
?>
    <tr>
    <td><?php echo $num++;?></td>
    <td><?php echo $row["s_id"];?></td>
    <td><?php echo $row["s_name"];?></td>
    <td><?php echo $row["s_sex"];?></td>
    <td><?php echo $row["s_class"];?></td>
    <td><?php echo $row["s_phone"];?></td>
    <td><a href=update.php?s_id=<?php echo $row["s_id"];?>>修改</a> | <a href=delete.php?s_id=<?php echo $row["s_id"];?>>删除</a></td>
    </tr>
<?php
}
?>
<tr>
<td align="center" colspan="7" height="50"> <?php echo $pagenav; //输出分页页码信息 ?></td>
</tr>
</table>
<table align="center">
<td align="center">
<tr align="center">
<a href="add.php"><button class="btn btn_submit J_install_btn">添加数据</button></a>
</tr>
<tr align="center">
<a href="login_ok.php?out=out"><button class="btn btn_submit J_install_btn">注销</button></a>
</tr>
</td>
</table>
</div>
</div>
</div>

<?php
mysqli_close($con);
?>
</body>
</html>