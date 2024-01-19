#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <locale.h>
#include <algorithm>

#ifdef _WIN32
#include <conio.h>
#endif
#define YELLOW  "\033[33m"
int finalRound();

int totalScoreA = 0;
int totalMistakesA = 0;
int totalScoreB = 0;
int totalMistakesB = 0;

int finalRound() {
    std::system("cls");

    
    int totalFinalScore = 0;

    // Pierwsza osoba
    std::cout << "Finał: Odpowiedzi osoby 1" << std::endl;
    std::vector<std::pair<std::string, int>> answersPerson1(5);

    for (int i = 0; i < 5; ++i) {
        std::cout << "Odpowiedź " << i + 1 << ": ";
        std::getline(std::cin, answersPerson1[i].first);
    }

    // Wprowadzanie punktów dla pierwszej osoby
    std::system("cls");
    int finalScorePerson1 = 0;

    for (int i = 0; i < 5; ++i) {
        std::cout << "Odpowiedź osoby 1: " << answersPerson1[i].first << "\nPodaj punkty: ";
        std::cin >> answersPerson1[i].second;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        finalScorePerson1 += answersPerson1[i].second;
    }

    // Druga osoba
    std::system("cls");
    std::cout << "Finał: Odpowiedzi osoby 2" << std::endl;
    std::vector<std::pair<std::string, int>> answersPerson2(5);

    for (int i = 0; i < 5; ++i) {
        std::cout << "Odpowiedź " << i + 1 << ": ";
        std::getline(std::cin, answersPerson2[i].first);
    }

    // Wprowadzanie punktów dla drugiej osoby
    std::system("cls");
    int finalScorePerson2 = 0;

    for (int i = 0; i < 5; ++i) {
        std::cout << "Odpowiedź osoby 2: " << answersPerson2[i].first << "\nPodaj punkty: ";
        std::cin >> answersPerson2[i].second;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        finalScorePerson2 += answersPerson2[i].second;
    }

    std::system("cls");
    // Wyświetlanie odpowiedzi w formie kolumn
    std::cout << "\n\nOsoba 1:\t\t\tOsoba 2:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << answersPerson1[i].first << "  " << answersPerson1[i].second << "\t\t" << answersPerson2[i].first << "  " << answersPerson2[i].second << std::endl;
    }

    // Zliczanie łącznej liczby punktów
    totalFinalScore = finalScorePerson1 + finalScorePerson2;

    return totalFinalScore;
}

// ... Reszta kodu bez zmian




struct Answer {
    std::string text;
    int points;
    bool revealed;
};


void display(const std::vector<Answer>& answers, int mistakesA, int mistakesB, int opponentPoints, int teamPoints) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    std::cout << "+----+------------------------------+----+" << std::endl;
    std::cout << "|    |                              |    |" << std::endl;
    for (int j = 0; j < 6; j++) {
        if (j < answers.size()) {
            if (answers[j].revealed) {
                std::cout << "| ";
                if (mistakesA * 2 >= j+1) {
                    if (j % 2 == 1) {
                        std::cout << "/\\";
                    }
                    else {
                        std::cout << "\\/";
                    }
                }
                else {
                    std::cout << "  ";
                }
                std::cout << " | " << j + 1 << ". " << answers[j].text;
                for (int i = 0; i < (23 - answers[j].text.length()); i++) {
                    std::cout << " ";
                }
                if (answers[j].points < 10) {
                    std::cout << " ";
                }
                std::cout << answers[j].points << " | ";
                if (mistakesB * 2 >= j+1) {
                    if (j % 2 == 1) {
                        std::cout << "/\\";
                    }
                    else {
                        std::cout <<  "\\/";
                    }
                }
                else {
                    std::cout << "  ";
                }
                std::cout <<" |" << std::endl;
                
            }
            else {
                std::cout << "| ";
                if (mistakesA * 2 >= j + 1) {
                    if (j % 2 == 1) {
                        std::cout << "/\\";
                    }
                    else {
                        std::cout << "\\/";
                    }
                }
                else {
                    std::cout << "  ";
                }
                std::cout << " | " << j + 1 << ". _ _ _ _ _ _ _ _ _ _ _  __ | ";
                if (mistakesB * 2 >= j + 1) {
                    if (j % 2 == 1) {
                        std::cout << "/\\";
                    }
                    else {
                        std::cout << "\\/";
                    }
                }
                else {
                    std::cout << "  ";
                }
                std::cout << " |" << std::endl;
            }
        }
        else {
            std::cout << "|    |                              |    |" << std::endl;
        }
        
    }
    std::cout << "|    |                              |    |" << std::endl;
    std::cout << "|    |                      SUMA ";
    
    if (teamPoints < 10) {
        std::cout << " ";
    }
    std::cout << teamPoints;
    std::cout << " |    |" << std::endl;
    std::cout << "+----+------------------------------+----+" << std::endl;
    //std::cout << "| " << totalScoreA << "                            " << totalScoreB << "|" << std::endl;

    std::cout << "+----------------------------------------+" << std::endl;
    std::cout << std::endl << std::endl;

    std::cout << "\n\n Błędy drużyny A: " << mistakesA << " / 3" << std::endl;
    std::cout << "Błędy drużyny B: " << mistakesB << " / 3" << std::endl;
    std::cout << "Punkty drużyny (" << (teamPoints == opponentPoints ? "A" : "B") << "): " << opponentPoints << std::endl;
    std::cout << "Punkty drużyny (" << (teamPoints == opponentPoints ? "B" : "A") << "): " << teamPoints << std::endl;
}

bool checkAndReveal(std::vector<Answer>& answers, int userInput, int& score) {
    if (userInput >= 1 && static_cast<size_t>(userInput) <= answers.size()) {
        auto& answer = answers[userInput - 1];
        if (!answer.revealed) {
            answer.revealed = true;
            score += answer.points;
            return true;
        }
    }
    return false;
}

int main() {


    std::cout << YELLOW;
    setlocale(LC_CTYPE, "Polish");

    std::vector<std::string> roundQuestions = {
        "Z czego słynie Francja?",
        "Co znajdziemy w łazience?",
        "Na czym można słuchać muzyki?",
        "Jakie zwierze można spotkać w Indiach?"
    };

    std::vector<std::vector<Answer>> rounds = {
        {
            {"Bagietki", 29, false},
            {"Wieża Eiffela", 23, false},
            {"Kapitulacja", 10, false},
            {"Imigranci", 9, false},
            {"Niepokoje Społeczne", 5, false},
            {"Croissant", 5, false},
        },
        {
            {"Mydło", 31, false},
            {"Zlew", 13, false},
            {"Wanna", 12, false},
            {"Toaleta", 11, false},
            {"Prysznic", 7, false},
            {"Ręcznik", 5, false},
        },
        {
            {"Słuchawkach", 29, false},
            {"Telefonie", 15, false},
            {"Głośniku", 12, false},
            {"Spotify", 11, false},
            {"MP3", 5, false},
            {"Radio", 4, false},
        },
        {
            {"Krowa", 35, false},
            {"Słoń", 31, false},
            {"Tygrys", 6, false},
            {"Małpy", 4, false},
        },
    };

    for (size_t roundIndex = 0; roundIndex < rounds.size(); ++roundIndex) {
        int roundScoreA = 0;
        int roundScoreB = 0;
        int roundMistakesA = 0;
        int roundMistakesB = 0;

        while ((roundMistakesA < 3 && roundMistakesB < 3) && std::any_of(rounds[roundIndex].begin(), rounds[roundIndex].end(), [](const Answer& ans) { return !ans.revealed; })) {
            display(rounds[roundIndex], roundMistakesA, roundMistakesB, totalScoreB, totalScoreA);

            std::cout << "Kto naciska przycisk? (wpisz 'A' dla drużyny A lub 'B' dla drużyny B): ";
            std::string currentResponder;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, currentResponder);

            int responder = currentResponder == "A" ? 1 : 2;
            int userInput;
            std::cout << "Podaj numer odpowiedzi: ";
            std::cin >> userInput;

            if (!checkAndReveal(rounds[roundIndex], userInput, (responder == 1) ? roundScoreA : roundScoreB)) {
                if (responder == 1) {
                    roundMistakesA++;
                }
                else {
                    roundMistakesB++;
                }
                std::cout << "Niepoprawny numer odpowiedzi!" << std::endl;
            }

            if (roundMistakesA >= 3 || roundMistakesB >= 3) {
                display(rounds[roundIndex], roundMistakesA, roundMistakesB, totalScoreB, totalScoreA);
                if (roundMistakesA == 3 && roundMistakesB == 1) {
                    // Specjalny przypadek: 3 błędy dla drużyny A, 1 błąd dla drużyny B
                    // Przyznaj punkty drużynie A za wszystkie poprawne odpowiedzi
                    for (const auto& answer : rounds[roundIndex]) {
                        if (answer.revealed) {
                            roundScoreA += answer.points;
                        }
                    }
                    totalScoreA += roundScoreA;  // Dodaj punkty za rundę do ogólnej liczby punktów dla drużyny A
                    roundScoreA = 0;  // Resetuj punkty za rundę dla drużyny A
                }
                else {
                    std::string stealingTeam = (roundMistakesA >= 3) ? "B" : "A";
                    int& opponentScore = (stealingTeam == "A") ? totalScoreA : totalScoreB;
                    int& currentRoundScore = (stealingTeam == "A") ? roundScoreB : roundScoreA;
                    int& teamsScore = (stealingTeam == "B") ? totalScoreA : totalScoreB;
                    int& teamsMistaces = (stealingTeam == "A") ? roundMistakesA : roundMistakesB;

                    std::cout << "Drużyna " << stealingTeam << " ma szansę na przejęcie punktów. Podaj numer odpowiedzi: ";
                    std::cin >> userInput;

                    if (checkAndReveal(rounds[roundIndex], userInput, currentRoundScore)) {
                        std::cout << "Drużyna " << stealingTeam << " przejmuje punkty!" << std::endl;
                        opponentScore += currentRoundScore;
                        currentRoundScore = 0;
                    }
                    else {
                        teamsMistaces += 1;
                        teamsScore += currentRoundScore;
                        std::cout << "Drużyna " << stealingTeam << " nie odgadła odpowiedzi - kontynuacja gry." << std::endl;
                    }
                }
            }


            bool allAnswersRevealed = std::all_of(rounds[roundIndex].begin(), rounds[roundIndex].end(), [](const Answer& ans) { return ans.revealed; });

            if (allAnswersRevealed) {
                totalScoreA += roundScoreA;
                totalScoreB += roundScoreB;

                roundScoreA = 0;
                roundScoreB = 0;
            }
        }

        display(rounds[roundIndex], roundMistakesA, roundMistakesB, totalScoreB, totalScoreA);

        if (roundIndex < rounds.size() - 1) {
            std::string continueInput;
            do {
                std::cout << "Czy chcesz kontynuować do następnej rundy? (tak/nie): ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, continueInput);
            } while (continueInput != "tak" && continueInput != "T" && continueInput != "nie");

            if (continueInput != "tak" && continueInput != "T") {
                break;
            }

            for (auto& answer : rounds[roundIndex]) {
                answer.revealed = false;
            }

            totalMistakesA = 0;
            totalMistakesB = 0;
            std::cout << "Przechodzisz do kolejnej rundy!" << std::endl;
        }

        if (totalScoreA >= 200 || totalScoreB >= 200) {
            std::cout << "Osiągnięto 200 punktów. Czas na finał!" << std::endl;
            int finalScore = finalRound();
            if (finalScore >= 200) {
                std::cout << "\n\n\n";
                std::cout << "Gratulacje! Wygraliście finał z wynikiem " << finalScore << " punktów!" << std::endl;
            }
            else {
                std::cout << "\n\n\n";
                std::cout << "Niestety, nie udało się osiągnąć 200 punktów w finale. Wasz wynik to: " << finalScore << " punktów." << std::endl;
            }
            break; // Przerwij pętlę po zakończeniu gry
        }

    }

    std::cout << "Gra zakończona! \n Wynik drużyny A: " << totalScoreA << " pkt, Błędy: " << totalMistakesA << std::endl;
    std::cout << "Wynik drużyny B: " << totalScoreB << " pkt, Błędy: " << totalMistakesB << std::endl;
    std::cout << "autor // szmurk0";
    return 0;
}

