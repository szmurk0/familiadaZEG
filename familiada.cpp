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
int roundScore = 0;

static void finalDisplay(std::vector<std::pair<std::string, int>> answersPerson1, std::vector<std::pair<std::string, int>> answersPerson2, int questionNumber, int totalFinalScore) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    std::cout << "+-------------------------------------------------------+" << std::endl;
    std::cout << "|                                                       |" << std::endl;
    if (questionNumber != 11) { //nie czepiaj się
        //wiersz 1
        std::cout << "| ";
        if (questionNumber >= 1) { // pytanie 1 - pytanie
            for (int i = 0; i < (23 - answersPerson1[0].first.length()); i++) {
                std::cout << " ";
            }
            std::cout << answersPerson1[0].first;
        }
        else {
            std::cout << "  _ _ _ _ _ _ _ _ _ _ _";
        }
        std::cout << " ";
        if (questionNumber >= 2) { // pytanie 1 - pkt
            if (answersPerson1[0].second < 10) {
                std::cout << " ";
            }
            std::cout << answersPerson1[0].second;
        }
        else {
            std::cout << "__";
        }
        std::cout << " ";
        if (questionNumber >= 13) { // pytanie 6 - pkt
            if (answersPerson2[0].second < 10) {
                std::cout << " ";
            }
            std::cout << answersPerson2[0].second;
        }
        else {
            std::cout << "__";
        }
        std::cout << " ";
        if (questionNumber >= 12) { // pytanie 6 - pytanie
            std::cout << answersPerson2[0].first;
            for (int i = 0; i < (23 - answersPerson2[0].first.length()); i++) {
                std::cout << " ";
            }
        }
        else {
            std::cout << "  _ _ _ _ _ _ _ _ _ _ _";
        }
        std::cout << " |" << std::endl;

        //wiersz 2
        std::cout << "| ";
        if (questionNumber >= 3) { // pytanie 2 - pytanie
            for (int i = 0; i < (23 - answersPerson1[1].first.length()); i++) {
                std::cout << " ";
            }
            std::cout << answersPerson1[1].first;
        }
        else {
            std::cout << "  _ _ _ _ _ _ _ _ _ _ _";
        }
        std::cout << " ";
        if (questionNumber >= 4) { // pytanie 2 - pkt
            if (answersPerson1[1].second < 10) {
                std::cout << " ";
            }
            std::cout << answersPerson1[1].second;
        }
        else {
            std::cout << "__";
        }
        std::cout << " ";
        if (questionNumber >= 15) { // pytanie 7 - pkt
            if (answersPerson2[1].second < 10) {
                std::cout << " ";
            }
            std::cout << answersPerson2[1].second;
        }
        else {
            std::cout << "__";
        }
        std::cout << " ";
        if (questionNumber >= 14) { // pytanie 6 - pytanie
            std::cout << answersPerson2[1].first;
            for (int i = 0; i < (23 - answersPerson2[1].first.length()); i++) {
                std::cout << " ";
            }
        }
        else {
            std::cout << "  _ _ _ _ _ _ _ _ _ _ _";
        }
        std::cout << " |" << std::endl;

        //wiersz 3
        std::cout << "| ";
        if (questionNumber >= 5) { // pytanie 3 - pytanie
            for (int i = 0; i < (23 - answersPerson1[2].first.length()); i++) {
                std::cout << " ";
            }
            std::cout << answersPerson1[2].first;
        }
        else {
            std::cout << "  _ _ _ _ _ _ _ _ _ _ _";
        }
        std::cout << " ";
        if (questionNumber >= 6) { // pytanie 3 - pkt
            if (answersPerson1[2].second < 10) {
                std::cout << " ";
            }
            std::cout << answersPerson1[2].second;
        }
        else {
            std::cout << "__";
        }
        std::cout << " ";
        if (questionNumber >= 17) { // pytanie 7 - pkt
            if (answersPerson2[2].second < 10) {
                std::cout << " ";
            }
            std::cout << answersPerson2[2].second;
        }
        else {
            std::cout << "__";
        }
        std::cout << " ";
        if (questionNumber >= 16) { // pytanie 7 - pytanie
            std::cout << answersPerson2[2].first;
            for (int i = 0; i < (23 - answersPerson2[2].first.length()); i++) {
                std::cout << " ";
            }
        }
        else {
            std::cout << "  _ _ _ _ _ _ _ _ _ _ _";
        }
        std::cout << " |" << std::endl;

        //wiersz 4
        std::cout << "| ";
        if (questionNumber >= 7) { // pytanie 4 - pytanie
            for (int i = 0; i < (23 - answersPerson1[3].first.length()); i++) {
                std::cout << " ";
            }
            std::cout << answersPerson1[3].first;
        }
        else {
            std::cout << "  _ _ _ _ _ _ _ _ _ _ _";
        }
        std::cout << " ";
        if (questionNumber >= 8) { // pytanie 4 - pkt
            if (answersPerson1[3].second < 10) {
                std::cout << " ";
            }
            std::cout << answersPerson1[3].second;
        }
        else {
            std::cout << "__";
        }
        std::cout << " ";
        if (questionNumber >= 19) { // pytanie 8 - pkt
            if (answersPerson2[3].second < 10) {
                std::cout << " ";
            }
            std::cout << answersPerson2[3].second;
        }
        else {
            std::cout << "__";
        }
        std::cout << " ";
        if (questionNumber >= 18) { // pytanie 7 - pytanie
            std::cout << answersPerson2[3].first;
            for (int i = 0; i < (23 - answersPerson2[3].first.length()); i++) {
                std::cout << " ";
            }
        }
        else {
            std::cout << "  _ _ _ _ _ _ _ _ _ _ _";
        }
        std::cout << " |" << std::endl;

        //wiersz 5
        std::cout << "| ";
        if (questionNumber >= 9) { // pytanie 4 - pytanie
            for (int i = 0; i < (23 - answersPerson1[4].first.length()); i++) {
                std::cout << " ";
            }
            std::cout << answersPerson1[4].first;
        }
        else {
            std::cout << "  _ _ _ _ _ _ _ _ _ _ _";
        }
        std::cout << " ";
        if (questionNumber >= 10) { // pytanie 4 - pkt
            if (answersPerson1[4].second < 10) {
                std::cout << " ";
            }
            std::cout << answersPerson1[4].second;
        }
        else {
            std::cout << "__";
        }
        std::cout << " ";
        if (questionNumber >= 21) { // pytanie 8 - pkt
            if (answersPerson2[4].second < 10) {
                std::cout << " ";
            }
            std::cout << answersPerson2[4].second;
        }
        else {
            std::cout << "__";
        }
        std::cout << " ";
        if (questionNumber >= 20) { // pytanie 7 - pytanie
            std::cout << answersPerson2[4].first;
            for (int i = 0; i < (23 - answersPerson2[4].first.length()); i++) {
                std::cout << " ";
            }
        }
        else {
            std::cout << "  _ _ _ _ _ _ _ _ _ _ _";
        }
        std::cout << " |" << std::endl;
    }
    else {
        std::cout << "|   _ _ _ _ _ _ _ _ _ _ _ __ __ _ _ _ _ _ _ _ _ _ _ _   |" << std::endl;
        std::cout << "|   _ _ _ _ _ _ _ _ _ _ _ __ __ _ _ _ _ _ _ _ _ _ _ _   |" << std::endl;
        std::cout << "|   _ _ _ _ _ _ _ _ _ _ _ __ __ _ _ _ _ _ _ _ _ _ _ _   |" << std::endl;
        std::cout << "|   _ _ _ _ _ _ _ _ _ _ _ __ __ _ _ _ _ _ _ _ _ _ _ _   |" << std::endl;
        std::cout << "|   _ _ _ _ _ _ _ _ _ _ _ __ __ _ _ _ _ _ _ _ _ _ _ _   |" << std::endl;
    }
    std::cout << "|                                                       |" << std::endl;
    std::cout << "|                                              SUMA ";
    if (totalFinalScore < 100) {
        std::cout << " ";
        if (totalFinalScore < 10) {
            std::cout << " ";
        }
    }
    std::cout << totalFinalScore;
    std::cout << " | " << std::endl;
    std::cout << "+-------------------------------------------------------+" << std::endl << std::endl << std::endl << std::endl;
}

int finalRound() {
    std::system("cls");

    std::cout << "+-------------------------------------------------------+" << std::endl;
    std::cout << "|                                                       |" << std::endl;
    std::cout << "|   _ _ _ _ _ _ _ _ _ _ _ __ __ _ _ _ _ _ _ _ _ _ _ _   |" << std::endl;
    std::cout << "|   _ _ _ _ _ _ _ _ _ _ _ __ __ _ _ _ _ _ _ _ _ _ _ _   |" << std::endl;
    std::cout << "|   _ _ _ _ _ _ _ _ _ _ _ __ __ _ _ _ _ _ _ _ _ _ _ _   |" << std::endl;
    std::cout << "|   _ _ _ _ _ _ _ _ _ _ _ __ __ _ _ _ _ _ _ _ _ _ _ _   |" << std::endl;
    std::cout << "|   _ _ _ _ _ _ _ _ _ _ _ __ __ _ _ _ _ _ _ _ _ _ _ _   |" << std::endl;
    std::cout << "|                                                       |" << std::endl;
    std::cout << "|                                              SUMA ___ |" << std::endl;
    std::cout << "+-------------------------------------------------------+" << std::endl << std::endl << std::endl << std::endl;

    int questionNumber = 0;
    std::string a = "a";

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
        questionNumber += 1;
        finalDisplay(answersPerson1, answersPerson1, questionNumber, totalFinalScore);
        std::cout << "Odpowiedź osoby 1: " << answersPerson1[i].first << "\nPodaj punkty: ";
        std::cin >> answersPerson1[i].second;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        totalFinalScore += answersPerson1[i].second;
        questionNumber += 1;
        finalDisplay(answersPerson1, answersPerson1, questionNumber, totalFinalScore);
        std::cout << "Wpisz dowolną wartość, aby pójść dalej: ";
        std::cin >> a;
    }


    questionNumber += 1;
    finalDisplay(answersPerson1, answersPerson1, questionNumber, totalFinalScore);

    // Druga osoba
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
        questionNumber += 1;
        finalDisplay(answersPerson1, answersPerson2, questionNumber, totalFinalScore);
        std::cout << "Odpowiedź osoby 2: " << answersPerson2[i].first << "\nPodaj punkty: ";
        std::cin >> answersPerson2[i].second;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        totalFinalScore += answersPerson2[i].second;
        questionNumber += 1;
        finalDisplay(answersPerson1, answersPerson2, questionNumber, totalFinalScore);
        std::cout << "Wpisz dowolną wartość, aby pójść dalej: ";
        std::cin >> a;
    }

    std::system("cls");
    // Wyświetlanie odpowiedzi w formie kolumn
    std::cout << "\n\nOsoba 1:\t\t\tOsoba 2:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << answersPerson1[i].first << "  " << answersPerson1[i].second << "\t\t" << answersPerson2[i].first << "  " << answersPerson2[i].second << std::endl;
    }

    // Zliczanie łącznej liczby punktów
    //totalFinalScore = finalScorePerson1 + finalScorePerson2;

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
                std::cout << " | " << j + 1 << ". " << answers[j].text;
                for (int i = 0; i < (23 - answers[j].text.length()); i++) {
                    std::cout << " ";
                }
                if (answers[j].points < 10) {
                    std::cout << " ";
                }
                std::cout << answers[j].points << " | ";
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

    if (roundScore < 10) {
        std::cout << " ";
    }
    std::cout << roundScore;
    std::cout << " |    |" << std::endl;
    std::cout << "+----+------------------------------+----+" << std::endl;
    std::cout << "| ";
    if (totalScoreA < 100) {
        std::cout << " ";
        if (totalScoreA < 10) {
            std::cout << " ";
        }
    }
    std::cout << totalScoreA << "                                ";
    if (totalScoreB < 100) {
        std::cout << " ";
        if (totalScoreB < 10) {
            std::cout << " ";
        }
    }
    std::cout << totalScoreB << " |" << std::endl;

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
            roundScore += answer.points;
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
        "",
        "",
        "",
        ""
    };

    std::vector<std::vector<Answer>> rounds = { // Tutaj mają być odpowiedzi do 1 pytania
        {
            {"pytanie1odpowiedz1", 40, false},
            {"pytanie1odpowiedz2", 17, false},
            {"pytanie1odpowiedz3", 15, false},
            {"pytanie1odpowiedz4", 9, false},
            {"pytanie1odpowiedz5", 7, false},
        },
        {
            {"pytanie2odpowiedz1", 20, false},
            {"pytanie2odpowiedz2", 17, false},
            {"pytanie2odpowiedz3", 15, false},
            {"pytanie2odpowiedz4", 14, false},
            {"pytanie2odpowiedz5", 10, false},
        },
        {
            {"pytanie3odpowiedz1", 33, false},
            {"pytanie3odpowiedz2", 21, false},
            {"pytanie3odpowiedz3", 14, false},
            {"pytanie3odpowiedz4", 10, false},
        },
        {
            {"pytanie4odpowiedz1", 35, false},
            {"pytanie4odpowiedz2", 28, false},
            {"pytanie4odpowiedz3", 14, false},
            {"pytanie4odpowiedz4", 13, false},
            {"pytanie4odpowiedz5", 10, false},
        },
        {
            {"pytanie5odpowiedz1", 35, false},
            {"pytanie5odpowiedz2", 31, false},
            {"pytanie5odpowiedz3", 6, false},
            {"pytanie5odpowiedz4", 4, false},
        },
    };

    for (size_t roundIndex = 0; roundIndex < rounds.size(); ++roundIndex) {
        int roundScoreA = 0;
        int roundScoreB = 0;
        int roundMistakesA = 0;
        int roundMistakesB = 0;

        if (roundIndex == 4) {
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
                            roundScoreA += roundScore;
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
                        opponentScore += roundScore;
                        roundScore = 0;
                        currentRoundScore = 0;
                    }
                    else {
                        teamsMistaces += 1;
                        teamsScore += roundScore;
                        roundScore = 0;
                        std::cout << "Drużyna " << stealingTeam << " nie odgadła odpowiedzi - kontynuacja gry." << std::endl;
                    }
                }
            }


            bool allAnswersRevealed = std::all_of(rounds[roundIndex].begin(), rounds[roundIndex].end(), [](const Answer& ans) { return ans.revealed; });

            if (allAnswersRevealed) {
                if (responder == 1) {
                    totalScoreA += roundScore;
                }
                else {
                    totalScoreB += roundScore;
                }


                roundScoreA = 0;
                roundScoreB = 0;
                roundScore = 0;
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



    }

    std::cout << "Gra zakończona! \n Wynik drużyny A: " << totalScoreA << " pkt, Błędy: " << totalMistakesA << std::endl;
    std::cout << "Wynik drużyny B: " << totalScoreB << " pkt, Błędy: " << totalMistakesB << std::endl;
    std::cout << "autor // szmurk0";
    return 0;
}

