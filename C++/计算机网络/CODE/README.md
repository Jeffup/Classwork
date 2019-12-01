### 1、 编译安装
加载项目后，在资源文件中添加以下文件
再配置环境：
在项目属性中：
1. 高级->高级属性->MFC的使用->“使用多字节字符集”
2. VC++目录->包含文件->“把文件夹WpdPack中的include文件夹包含进来”
3. VC++目录->库目录->“把文件夹WpdPack中的lib文件夹包含进来”
4. C/C++->预处理器-> “_WINSOCK_DEPRECATED_NO_WARNINGS;HAVE_REMOTE;WPCAP;WIN32;_WINDOWS;_DEBUG;%(PreprocessorDefinitions)”
5. 链接器->附加依赖项->“Packet.lib;wpcap.lib;”

按照步骤执行即可完成配置环境。
然后直接编译即可！

### 2、 使用说明
1. 必须先点击扫描适配器才能进行往后的操作。
2. 必须点击下拉列表中的数字（索引）才算是真正选中
3. 软件抓包分析时间较为漫长，请耐心等待
4. 抓的MAC地址不仅仅回事内网的，若联网，则也会抓与本机相连的主机MAC地址
