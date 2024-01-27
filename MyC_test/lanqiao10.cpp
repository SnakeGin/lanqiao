//激光样例
//引用他人源码
//算是动规的一种
#include <iostream>
using namespace std;
int laserStyle(int number);
int main()
{
  int number=30;
  cout<<laserStyle(number)<<endl;
  return 0;
}
int laserStyle(int number)
{
  //零台激光只有一种样式：(1)没有光！
  if(number==0) return 1;          

  //一台激光有两种样式：(1)没有光！(2)开一台
  else if(number==1) return 2;
  
  /*不失一般性，可以约定：第number台激光被加入到左边(number-1)台激光所排一字的最右边，
    则依据第number台激光是否打开，在计算number台激光所拥有的样式数量时，可以分为两种情形：
    (1)如果第number台激光没有打开，则此时的样式数量就是：左边(number-1)台激光所拥有的样式数量。
    (2)如果第number台激光已经打开，则紧挨着它的左数第(number-1)台激光必须关闭，
    那么此时的样式数量就是：左边(number-2)台激光所拥有的样式数量。
  */
  else return laserStyle(number-1)+
              laserStyle(number-2);
}