MFC中listbox控件是为了显示一系列的文本，每个文本占一行。

Listbox控件可以设置属性为：
LBS_CHILD   ：（默认）子窗口
LBS_Visible ：（默认）可视
LBS_Multiplesel ：可选择多行
LBS_Extendedsel ：可以使用shift或ctrl选择多行
LBS_SORT：所有行按字母顺序进行排序

对Listbox进行操作：
Intlistbox.AddString (  LPCTSTR     Str)   ：对listbox的首行添加一个str的文本行,即此时nIndex为0；
Intlistbox.DeleteString (uint nIndex)     ：删除listbox中第nIndex行的文本行，注意nIndex是从0起始的；
intlistbox.InsertString (uint xIndex, LPCTSTR  Str)：在listbox中第nIndex行插入一个str的文本行；
Int listbox.GetCount (  )：获取listbox的行的总数目；
Int listbox.GetCurSel  ( )：得到listbox选中的文本行的行数。
Void listbox.ResetContent (  )：清除listbox中的所有数据；
Intlistbox.GetCurCount ( )：获取listbox被选中的行的数目；
Intlistbox.FindString  ( int nstart , LPCTSTR  Str )：从第nstart行开始起进行查找，查找Str的文本行；
Intlistbox.SelectString ( int nstart, LPCTSTR Str ) ：从第nstart行开始，选择包含Str字符串的那一行；

对Listbox中某一行进行双击操作，要产生一个响应函数的步骤：
在
BEGIN_MESSAGE_MAP()
END_MESSAGE_MAP()
之间添加响应函数的消息映射，如函数名为C\*\*Dlg::OnLbnDblClk，添加下面代码
ON_LBN_DBLCLK(IDC_LIST1,&C\*\*Dlg::OnLbnDblClk)
//IDC_LIST1为listbox控件的ID
然后在C\*\*Dlg.h中添加函数OnLbnDblClk()的声明
最后在C\*\*Dlg::OnLbnDblClk()函数中添加实现代码即可

