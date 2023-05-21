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
    int posX;                  // X ��ġ
    int posY;                  // Y ��ġ
    bool active;            // Ȱ��ȭ ���� �÷���
    std::vector<Component*> components;  // ������Ʈ���� ����Ʈ
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

    void RemoveComponent(Component* component) // ��ü���� ������Ʈ ����
    {
        components.erase(std::remove(components.begin(), components.end(), component), components.end());
        delete component;
    }

    void Render(char* screenBuffer) // ��ü�� ȭ�� ���ۿ� ������
    {
        
        const char* objectString = "****"; // ��ü�� ��Ÿ���� ���ڿ�

        
        for (int i = 0; i < 4; i++) // ��ü�� ��ġ�� ���ڿ��� �����Ͽ� ȭ�� ���ۿ� ���
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

class Scene // Scene Ŭ����
{
private:
    std::vector<Object*> objects;  // Scene ���� ��ü���� ����Ʈ
    char* screenBuffer;           // ȭ�� ����
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

    void InitScreenBuf() // ȭ�� ���� �ʱ�ȭ
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

        
        for (int i = 1; i < screenHeight - 1; i++) // �߰� ����
        {
            screenBuffer[i * screenWidth] = '*';
            screenBuffer[i * screenWidth + screenWidth - 1] = '*';
        }

        
        for (int i = 0; i < screenWidth; i++) // �ϴ� �׵θ�
        {
            screenBuffer[(screenHeight - 1) * screenWidth + i] = '*';
        }
    }

    void Draw()
    {

        ShowScreenBuf();    

        for (std::vector<Object*>::iterator it = objects.begin(); it != objects.end(); ++it) // Ȱ��ȭ�� ��ü ������
        {
            Object* object = *it;
            if (object->IsActive()) {
                object->Render(screenBuffer);
            }
        }

        for (int i = 0; i < screenHeight; i++) // ȭ�� ���� �׸���
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

    void RemoveObject(Object* object) // Scene���� ��ü ����
    {
        
        objects.erase(std::remove(objects.begin(), objects.end(), object), objects.end());
        delete object;
    }

    void ClearObjects() // Scene���� ��� ��ü ����
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

    
    std::cout << "���� ����" << std::endl; // ���� ���� ȭ�� ���
    std::cout << "A�� ������ ����˴ϴ�." << std::endl;

    bool gameRunning = true;

    while (gameRunning) // ���� ����
    {
        char userInput = _getch();
        if (userInput == 'a')
        {
            Object* object = new Object(5, 3, screenWidth);
            Component* component = new Component(); // ������Ʈ ����
            object->AddComponent(component); // ������Ʈ�� ��ü�� �߰�
            scene.AddObject(object);   

            scene.Draw(); // Scene ������

            gameRunning = true;
        }
        else if (userInput == 'b')
        {
            std::cout << "���� ����" << std::endl; // ���� ����
            gameRunning = false;
        }

    }

    return 0;
}
