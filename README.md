# Project-Albacore

## Albacore- Graphic

제 프로젝트 알바코어의 그래픽스를 담당할 코드입니다. CS180에서 배운 내용들을 응용해서 만들고 싶어서 그래픽 프레임워크를 DLL로 만들기로 했음  

![](C:\Users\ttuan\Desktop\project%20setting.png)

현재는 Albacore-Game 코드가 Albacore-Graphic를 참조하고 있슴 사실  이러면 static_library를 사용하는것과 큰차이가 없게 되는데  나중에 함수포인터를 받아서  사용할 수 있게 고칠 거임 

```c++
//Name : Jinseok Son
//Date : 1/3/2023 
//Description : Graphic Engine Window File

#pragma once

#ifdef  DLL_EXPORTS
#define ALBACORE_GRAPHIC_DECLSPEC __declspec(dllexport)
#else
#define ALBACORE_GRAPHIC_DECLSPEC __declspec(dllimport)
#endif
namespace Albacore
{
    class Window
    {
    public:
         static  bool  ALBACORE_GRAPHIC_DECLSPEC create_window();



    };
}

```

2023/1/3일에 만든 opengl context 와 window를만들기 위해 짠 코드임 이코드를 짜면서 어려웠던것은 

```c++
#ifdef  DLL_EXPORTS
#define ALBACORE_GRAPHIC_DECLSPEC __declspec(dllexport)
#else
#define ALBACORE_GRAPHIC_DECLSPEC __declspec(dllimport)
```

 이부분이였음 옛날에 한번 cs180 시간에 햅을 하면서 만들어보긴 했는데 다시 해보니까 어려웠음 이코들 짜면서 조건부 컴파일에 대해서 공부하게 됨  생각보다 간단했음 

내 프로젝트에 DLL_EXPORT라는 기호가 정의되어 있으면  이코드는  DLL파일에 있는 데이터나 함수를 다른 응용프로그램이 쓸수 있게 노출시킨다는 뜻임

 내프로젝트에 DLL_EXPORT라는 기호가 정의되어 있지 않으면 이코드는 DLL파일에서 노출시킨 데이터나 함수를 사용하겠다는 뜻임 

![](C:\Users\ttuan\Desktop\전처리기.png)

여기보면 알겟지만 Albacore-Graphic 는 전처리기에 DLL_EXPORTS가 정의되어 았음 DLL_EXPORT가 전역적으로 정의 되어 있기 때문에 Albacore-Graphic은   ```LBACORE_GRAPHIC_DECLSPEC``` 정의되어 있으면 이파일들을 바깥으로 노출시킴  전처리기 정의를 하지 않아 시간을 꽤나 많이 잡아먹었었음 

![](C:\Users\ttuan\Desktop\셋팅.png)



warning Level4 + Treat Warning As Erros 는 국룰임 




































