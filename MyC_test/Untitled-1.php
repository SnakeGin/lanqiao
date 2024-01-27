//URL(链接)字符串
$url = 'http://223.129.86.2:32992/cache.php/?name=Hello';
//parse_url 函数从一个 URL 字符串中获取参数
$url=parse_url($url);
//输出获取到的内容
echo "<pre>";
