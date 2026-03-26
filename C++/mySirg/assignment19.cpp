#include<iostream>
#include<string.h>
using namespace std;
class Game
{
    private:
        int Score[5];
    public:
        void setScore(int score)
        {
            cout << "enter scores roundwise -"<< endl;
            for(int i = 0; i < 5; i++)
            Score[i] = score;
        }
        int getScore(int round)
        {
            return Score[round];
        }
};
class GameResult : public Game
{
    private:
        int Result[5];
    public:
        void setResult()
        {
            cout << "Enter 2 for win, 0 for loose and 1 for draw :" << endl;
            for(int i = 0; i < 5; i++)
            cin >> Result[i];
        }
        int getResult(int round)
        {
            return Result[round];
        }
        int finalResult()
        {
            int s = 0;
            for(int i = 0; i < 5; i++)
            {
                s += getResult(i);
            }
        }
};
class Actor
{
    private:
        char name[20];
        int age;
    public:
        void setName(char n[])
        {
            strcpy(name,n);
        }
        void setAge(int a)
        {
            age = a;
        }
        char* getName()
        {
            return name;
        }
        int getAge()
        {
            return age;
        }
};
class TVActor : virtual public Actor
{
    private:
        int TVprojects;
    public:
        void setTVprojects(int t)
        {
            TVprojects = t;
        }
        int getTVprojects()
        {
            return TVprojects;
        }
        void setTVActor(char n[], int a, int t)
        {
            setName(n);
            setAge(a);
            setTVprojects(t);
        }
        void showTVActor()
        {
            cout << "Name :" << getName() << endl;
            cout << "Age :" << getAge() << endl;
            cout << "TVprojects done or running:" << getTVprojects() << endl;
        }
};
class MovieActor : virtual public Actor
{
    private:
        int Movies;
    public:
        void setMovies(int t)
        {
            Movies = t;
        }
        int getMovies()
        {
            return Movies;
        }
        void setMovieActor(char n[], int a, int t)
        {
            setName(n);
            setAge(a);
            setMovies(t);
        }
        void showTVActor()
        {
            cout << "Name :" << getName() << endl;
            cout << "Age :" << getAge() << endl;
            cout << "Movies done or running:" << getMovies() << endl;
        }
};
class AllScreenActor : public TVActor, public MovieActor
{
    public:
        void setAllScreenActor(char n[], int a, int t, int m, int p)
        {
            setName(n);
            setAge(a);
            setTVprojects(t);
            setMovies(m);
        }
        void showAllScreenActor()
        {
            cout << "Name :" << getName() << endl;
            cout << "Age :" << getAge() << endl;
            cout << "Movies done or running:" << getTVprojects() << endl;
            cout << "Movies done or running:" << getMovies() << endl;
        }
};
int main()
{

    return 0;
} 