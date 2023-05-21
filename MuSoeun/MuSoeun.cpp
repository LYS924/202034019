#include <iostream>
#include <vector>
#include <conio.h>

class Object;

class Component
{
public:
    virtual void Update() {}
};

class Object
{
private:
    int posX;                  // X 위치
    int posY;                  // Y 위치
    bool active;            // 활성화 상태 플래그
    std::vector<Component*> components;  // 컴포넌트들의 리스트
    int screenWidth;

public:
    Object(int xPos, int yPos, int width) : posX(xPos), posY(yPos), active(true), screenWidth(width) {}

    virtual ~Object()
    {
        for (Component* component : components)
        {
            delete component;
        }
        components.clear();
    }

    void AddComponent(Component* component)
    {
        components.push_back(component);
    }

    void RemoveComponent(Component* component) // 객체에서 컴포넌트 제거
    {
        components.erase(std::remove(components.begin(), components.end(), component), components.end());
        delete component;
    }

    void Render(char* screenBuffer) // 객체를 화면 버퍼에 렌더링
    {
        
        const char* objectString = "****"; // 객체를 나타내는 문자열

        
        for (int i = 0; i < 4; i++) // 객체의 위치에 문자열을 복사하여 화면 버퍼에 출력
        {
            int bufferIndex = (posY * screenWidth) + posX + i;
            screenBuffer[bufferIndex] = objectString[i];
        }
    }

    bool IsActive() const
    {
        return active;
    }

    void SetActive(bool isActive)
    {
        active = isActive;
    }

    void SetPosition(int xPos, int yPos)
    {
        posX = xPos;
        posY = yPos;
    }
};

class Scene // Scene 클래스
{
private:
    std::vector<Object*> objects;  // Scene 내의 객체들의 리스트
    char* screenBuffer;           // 화면 버퍼
    int screenWidth;
    int screenHeight;

public:
    Scene(int width, int height) : screenWidth(width), screenHeight(height)
    {
        screenBuffer = new char[screenWidth * screenHeight];
        InitScreenBuf();
    }

    ~Scene()
    {
        delete[] screenBuffer;
        ClearObjects();
    }

    void InitScreenBuf() // 화면 버퍼 초기화
    {
        for (int i = 0; i < screenWidth * screenHeight; i++) {
            screenBuffer[i] = ' ';
        }
    }

    void ShowScreenBuf()
    {
        for (int i = 0; i < screenWidth; i++)
        {
            screenBuffer[i] = '*';
        }

        
        for (int i = 1; i < screenHeight - 1; i++) // 중간 내용
        {
            screenBuffer[i * screenWidth] = '*';
            screenBuffer[i * screenWidth + screenWidth - 1] = '*';
        }

        
        for (int i = 0; i < screenWidth; i++) // 하단 테두리
        {
            screenBuffer[(screenHeight - 1) * screenWidth + i] = '*';
        }
    }

    void Draw()
    {

        ShowScreenBuf();    

        for (std::vector<Object*>::iterator it = objects.begin(); it != objects.end(); ++it) // 활성화된 객체 렌더링
        {
            Object* object = *it;
            if (object->IsActive()) {
                object->Render(screenBuffer);
            }
        }

        for (int i = 0; i < screenHeight; i++) // 화면 버퍼 그리기
        {
            for (int j = 0; j < screenWidth; j++)
            {
                std::cout << screenBuffer[i * screenWidth + j];
            }
            std::cout << std::endl;
        }
    }

    void AddObject(Object* object)
    {
        objects.push_back(object);
    }

    void RemoveObject(Object* object) // Scene에서 객체 제거
    {
        
        objects.erase(std::remove(objects.begin(), objects.end(), object), objects.end());
        delete object;
    }

    void ClearObjects() // Scene에서 모든 객체 제거
    {
        
        for (Object* object : objects) {
            delete object;
        }
        objects.clear();
    }
};



int main() {
    const int screenWidth = 50;
    const int screenHeight = 25;
    Scene scene(screenWidth, screenHeight);

    
    std::cout << "게임 시작" << std::endl; // 게임 시작 화면 출력
    std::cout << "A를 누르면 실행됩니다." << std::endl;

    bool gameRunning = true;

    while (gameRunning) // 게임 루프
    {
        char userInput = _getch();
        if (userInput == 'a')
        {
            Object* object = new Object(5, 3, screenWidth);
            Component* component = new Component(); // 컴포넌트 생성
            object->AddComponent(component); // 컴포넌트를 객체에 추가
            scene.AddObject(object);   

            scene.Draw(); // Scene 렌더링

            gameRunning = true;
        }
        else if (userInput == 'b')
        {
            std::cout << "게임 종료" << std::endl; // 게임 종료
            gameRunning = false;
        }

    }

    return 0;
}
