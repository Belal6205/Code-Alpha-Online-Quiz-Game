#include <iostream>
#include <string>

using namespace std;

const int MAX_QUESTIONS = 10;  // Define a maximum number of questions per topic
const int NUM_TOPICS = 4;      // Number of topics

enum Topic {
    OLYMPIC,
    HISTORY,
    GEOGRAPHY,
    CARS
};

class Question {
public:
    Question(const string& q = "", const string& a = "") : question(q), answer(a) {}

    void setQuestion(const string& q) {
        question = q;
    }

    void setAnswer(const string& a) {
        answer = a;
    }

    void display() const {
        cout << question << endl;
    }

    bool checkAnswer(const string& userAnswer) const {
        return userAnswer == answer;
    }

private:
    string question;
    string answer;
};

class Quiz {
public:
    Quiz() : numQuestions(0) {}

    void addQuestion(const Question& q) {
        if (numQuestions < MAX_QUESTIONS) {
            questions[numQuestions] = q;
            numQuestions++;
        } else {
            cout << "Cannot add more questions. Max limit reached." << endl;
        }
    }

    void start() {
        string userAnswer;
        int score = 0;

        for (int i = 0; i < numQuestions; ++i) {
            questions[i].display();
            cout << "Your answer: ";
            getline(cin, userAnswer);

            if (questions[i].checkAnswer(userAnswer)) {
                score++;
            }
        }

        displayResults(score);
    }

private:
    Question questions[MAX_QUESTIONS];
    int numQuestions;

    void displayResults(int score) const {
        cout << "\nQuiz finished! Your score: " << score << " out of " << numQuestions << endl;
    }
};

class User {
public:
    User(const string& n = "") : name(n) {}

    void setName(const string& n) {
        name = n;
    }

    string getName() const {
        return name;
    }

private:
    string name;
};

class QuizGame {
public:
    QuizGame() {
        initializeQuizzes();
    }

    void registerUser() {
        string name;
        cout << "Enter your name: ";
        getline(cin, name);
        user.setName(name);
        cout << "User registered: " << user.getName() << endl;
    }

    void startQuiz() {
        int choice;
        cout << "Choose a topic:\n";
        cout << "1. Olympic\n";
        cout << "2. History\n";
        cout << "3. Geography\n";
        cout << "4. Cars\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        cin.ignore();  // Clear newline from the input buffer

        if (choice < 1 || choice > NUM_TOPICS+1) {


            cout << "Invalid choice. Exiting.\n";
            return;
        }

        Topic topic = static_cast<Topic>(choice-1);
        quizzes[topic].start();
    }

private:
    User user;
    Quiz quizzes[NUM_TOPICS];

    void initializeQuizzes() {
        // Olympic Quiz
        quizzes[OLYMPIC].addQuestion(Question("Who won the gold medal in men's 100m at the 2020 Olympics?", "Marcell Jacobs"));
        quizzes[OLYMPIC].addQuestion(Question("In which city were the 2016 Summer Olympics held?", "Rio de Janeiro"));

        // History Quiz
        quizzes[HISTORY].addQuestion(Question("Who was the first President of the United States?", "George Washington"));
        quizzes[HISTORY].addQuestion(Question("In which year did the Titanic sink?", "1912"));

        // Geography Quiz
        quizzes[GEOGRAPHY].addQuestion(Question("What is the capital of Australia?", "Canberra"));
        quizzes[GEOGRAPHY].addQuestion(Question("Which river is the longest in the world?", "Nile"));

        // Cars Quiz
        quizzes[CARS].addQuestion(Question("What company produces the Mustang?", "Ford"));
        quizzes[CARS].addQuestion(Question("Which car model is known as 'The Beetle'?", "Volkswagen"));
    }
};

int main() {
    QuizGame game;

    game.registerUser();
    game.startQuiz();

    return 0;
}
