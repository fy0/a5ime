
A5IME
==============

IME support for Allegro 5.

Only works on windows.

Now it's very simple.

I'll add more features in the future.


中文用户直接往这看。

这里是 Allegro 5 的中文输入支持，大概也可以扩大范围到中日韩三国输入吧，只适用于 Windows。

目前在 Win8 + VC2012 + A5 5.1.8 上进行了测试，很不幸的，只能支持微软拼音。

搜狗大概是比较奇葩，它不会触发任何IME消息，我十分的想不明白。

总之，先做出来。如果有同学知道怎么回事欢迎与我联系或者fork。

不过大概国内没什么人用 Allegro 吧，而我用它的原因可能单纯是不喜欢 SDL，后来知道 MUGEN 也是基于它的。

反正希望有人能用到。


## How to use:

1. Add a5ime.h and a5ime.cpp to your project.
2. Call a5ime_enable after display created.
3. Do something with ALLEGRO_EVENT_IME_KEY_CHAR.


## 怎么用:

1. 把 a5ime.h 和 a5ime.cpp 加进项目
2. display创建好之后调用 a5ime_enable(...)
3. 处理 ALLEGRO_EVENT_IME_KEY_CHAR 事件
