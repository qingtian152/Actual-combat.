#include <iostream>
#include <string>
using namespace std;

#define MAX 1000//�������

//�����ϵ�˵Ľṹ��
struct Person
{
    //����
    string m_Name;
    //�Ա� 1 �� 2 Ů
    int m_Sex;
    //����
    int m_Age;
    //�绰
    string m_Phone;
    //סַ
    string m_Addr;
};

//���ͨѶ¼�Ľṹ��
struct Addressbooks
{
    //ͨѶ¼�б������ϵ������
    struct Person personArray[MAX];
    //ͨѶ¼�е�ǰ��¼��ϵ�˸���
    int m_Size;
};

void showMenu() //��ӡ�˵�
{
    cout << "**************************" << endl;
    cout << "*****  1�������ϵ�� *****" << endl;
    cout << "*****  2����ʾ��ϵ�� *****" << endl;
    cout << "*****  3��ɾ����ϵ�� *****" << endl;
    cout << "*****  4��������ϵ�� *****" << endl;
    cout << "*****  5���޸���ϵ�� *****" << endl;
    cout << "*****  6�������ϵ�� *****" << endl;
    cout << "*****  0���˳�ͨѶ¼ *****" << endl;
    cout << "**************************" << endl;
}

//1�������ϵ��
void addPerson(Addressbooks * abs)
{
    //�ж�ͨѶ¼�Ƿ����������˾Ͳ������
    if (abs->m_Size == MAX)
    {
        cout << "ͨѶ¼�������޷����! " << endl;
    }
    else
    {
        //��Ӿ�����ϵ��

        //����
        string name;
        cout << "����������: " << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        //�Ա�
        int sex = 0;
        cout << "�������Ա�: 1->�� 2->Ů" << endl;
        while (true)
        {
            //���������� 1 ���� 2 �����˳�ѭ������Ϊ���������ȷֵ
            //��������������������
            cin >> sex;
            if(sex == 1 || sex == 2){
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout << "������������������!" << endl;
        }

        //����
        int age = 0;
        cout << "����������: " << endl;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        //�绰
        string phone;
        cout << "��������ϵ�绰: " << endl;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        //סַ
        string address;
        cout << "�������ͥסַ: " << endl;
        cin >> address;
        abs->personArray[abs->m_Size].m_Addr = address;

        //����ͨѶ¼����
        abs->m_Size++;

        cout << "��ӳɹ�" << endl;

        system("pause"); //�밴���������
        system("cls"); //��������
    }
}

//2����ʾ��ϵ��
void showPerson(Addressbooks * abs)
{
    //�ж�ͨѶ¼�������Ƿ�Ϊ0�����Ϊ0����ʾ��¼Ϊ��
    //�����Ϊ�գ���ʾ��¼����ϵ����Ϣ
    if (abs->m_Size == 0)
    {
        cout << "��ǰ��¼Ϊ��!" << endl;
    }
    else
    {
        for (int i = 0; i < abs->m_Size; i++)
        {
            cout << "����: " << abs->personArray[i].m_Name << "\t";
            cout << "�Ա�: " << ( abs->personArray[i].m_Sex == 1 ? "��":"Ů" ) << "\t";
            cout << "����: " << abs->personArray[i].m_Age << "\t";
            cout << "�绰: " << abs->personArray[i].m_Phone << "\t";
            cout << "סַ: " << abs->personArray[i].m_Addr << endl;
        }
    }

    system("pause"); //�����������
    system("cls"); //����
}

//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ�����������еľ���λ�ã������ڷ���-1
//����1 ͨѶ¼ ����2 �Ա�����
int isExist(Addressbooks * abs, string name)
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        if(abs->personArray[i].m_Name == name)
        {
            return i; //�ҵ��ˣ�����������������е��±���
        }
    }
    return -1; //�������������û���ҵ�������-1
}

//3��ɾ����ϵ��
void deletePerson(Addressbooks * abs)
{
    cout << "��������Ҫɾ������ϵ��" << endl;

    string name;
    cin >> name;

    //ret == -1 δ�鵽
    //ret != -1 �鵽��
    int ret = isExist(abs, name);
    if(ret != -1)
    {
        //���ҵ���Ҫ����ɾ������
        for(int i = ret; i < abs->m_Size; i++)
        {
            //����ǰ��
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_Size--; //����ͨѶ¼�е���Ա��
        cout << "ɾ���ɹ�!" << endl;
    }
    else
    {
        cout << "���޴���!" << endl;
    }
    system("pause"); //�����������
    system("cls"); //����
}

//4��������ϵ��
void findPerson(Addressbooks * abs)
{
    cout << "��������Ҫ���ҵ���ϵ��" << endl;
    string name;
    cin >> name;
    //�ж�ָ������ϵ���Ƿ����
    int ret = isExist(abs, name);
    if(ret != -1) //�ҵ���ϵ��
    {
        cout << "�ҵ���ϵ��!" << endl;
        cout << "����: " << abs->personArray[ret].m_Name << "\t";
        cout << "�Ա�: " << ( abs->personArray[ret].m_Sex == 1 ? "��":"Ů" ) << "\t";
        cout << "����: " << abs->personArray[ret].m_Age << "\t";
        cout << "�绰: " << abs->personArray[ret].m_Phone << "\t";
        cout << "סַ: " << abs->personArray[ret].m_Addr << endl;
    }
    else //δ�ҵ���ϵ��
    {
        cout << "���޴���!" << endl;
    }
    system("pause"); //�����������
    system("cls"); //����
}

//5���޸���ϵ��
void modifyPerson(Addressbooks * abs)
{
    cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
    string name;
    cin >> name;
    //�ж�ָ������ϵ���Ƿ����
    int ret = isExist(abs, name);
    if(ret != -1) //�ҵ���ϵ��
    {
        cout << "���������ϵ���޸ĺ����Ϣ: " << endl;
        //����
        string name;
        cout << "����������: " << endl;
        cin >> name;
        abs->personArray[ret].m_Name = name;

        //�Ա�
        int sex = 0;
        cout << "�������Ա�: 1->�� 2->Ů" << endl;
        while (true)
        {
            //���������� 1 ���� 2 �����˳�ѭ������Ϊ���������ȷֵ
            //��������������������
            cin >> sex;
            if(sex == 1 || sex == 2){
                abs->personArray[ret].m_Sex = sex;
                break;
            }
            cout << "������������������!" << endl;
        }

        //����
        int age = 0;
        cout << "����������: " << endl;
        cin >> age;
        abs->personArray[ret].m_Age = age;

        //�绰
        string phone;
        cout << "��������ϵ�绰: " << endl;
        cin >> phone;
        abs->personArray[ret].m_Phone = phone;

        //סַ
        string address;
        cout << "�������ͥסַ: " << endl;
        cin >> address;
        abs->personArray[ret].m_Addr = address;

        cout << "�޸ĳɹ�!" << endl;

    }
    else //δ�ҵ���ϵ��
    {
        cout << "���޴���!" << endl;
    }
    system("pause"); //�����������
    system("cls"); //����
}

//6�������ϵ��
void cleanPerson(Addressbooks * abs)
{
    cout << "��ȷ��Ҫ�����ϵ����?" << endl;
    cout << "1->�� 2->��" << endl;
    int decision = 0;
    while(true)
    {
        //����û�������� 1 ���ʾ��Ҫ�����ϵ��
        //����û�������� 2 ���ʾ�������
        //����û������������������
        cin >> decision;
        if( decision == 1 ){
            abs->m_Size = 0; //����ǰ��¼��ϵ��������Ϊ0�����߼���ղ���
            cout << "ͨѶ¼�����!" << endl;
            break;
        }
        else if( decision == 2 ){
            break;
        }
        cout << "������������������!" << endl;
    }
    system("pause"); //�����������
    system("cls"); //����
}

int main()
{
    //����ͨѶ¼�ṹ�����
    Addressbooks abs;
    //��ʼ��ͨѶ¼�е�ǰ��Ա����
    abs.m_Size = 0;

    int select = 0;
    while(true){
        showMenu(); //�˵�����
        cin >> select;
        switch (select)
        {
        case 1: //1�������ϵ��
            addPerson(&abs); //���õ�ַ���ݣ����������β�
            break;
        case 2: //2����ʾ��ϵ��
            showPerson(&abs);
            break;
        case 3: //3��ɾ����ϵ��
        // {
        //     cout << "������ɾ����ϵ�˵�����: " << endl;
        //     string name;
        //     cin >> name;

        //     if(isExist(&abs, name) == -1)
        //     {
        //         cout << "���޴���!" << endl;
        //     }
        //     else
        //     {
        //         cout << "�ҵ�����!" << endl;
        //     }
        // }
            deletePerson(&abs);
            break;
        case 4: //4��������ϵ��
            findPerson(&abs);
            break;
        case 5: //5���޸���ϵ��
            modifyPerson(&abs);
            break;
        case 6: //6�������ϵ��
            cleanPerson(&abs);
            break;
        case 0: //0���˳�ͨѶ¼
            cout << "��ӭ�´�ʹ��" << endl;
            system("pause");
            return 0;
            break;
        
        default:
            break;
        }
    }
    system("pause");
    return 0;
}