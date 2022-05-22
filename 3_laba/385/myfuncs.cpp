#include <string>
#include <vector>

#include "functions.h"

extern int n;


double minumum = 1000000000;
int line_with_min_number = 0;


std::string my_function(std::vector< std::vector <double> > my_matrix) 
{  
    using namespace std;

    string answer;

    if (find(my_matrix)){
        answer = "Минимальный элемент единственный по условию задачи";
        cout << "Элемент " << minumum << "должен встречаться ровно один раз" << endl;
        
    } else {
        answer = "Сумма элементов строки: ";
        answer +=  to_string(getSum(my_matrix));
    }

    return answer;
}


bool find(std::vector< std::vector <double> > my_matrix)
{
    int count = 0;
    for (int i = 0; i < my_matrix.size(); i++){
        for (int j = 0; j < my_matrix.size(); j++){
            if (my_matrix[i][j] == minumum)
                count += 1;
            if (count == 2)
                return true;
        }
    }

    return false;
}


std::vector <double> get_vector(std::string now_line, int string_number)
{
    using namespace std;

    vector  <double> _now_vector;
    string now_str = "";
    
    double tmp_number;
    int len_str = now_line.size();

    if (now_line[now_line.size() - 1] == ' ')
        len_str -= 1;

    for (int i = 0; i < len_str; i++)
    {
        if (now_line[i] != ' ') {
            now_str += now_line[i];
        } else 
        {   
            tmp_number = stod(now_str);
            _now_vector.push_back(tmp_number);
            now_str = "";

            if (tmp_number < minumum) {
                minumum = tmp_number;
                line_with_min_number = string_number;
            }
        }
    }

    tmp_number = stod(now_str);
    _now_vector.push_back(tmp_number);
    if (tmp_number < minumum) {
        minumum = tmp_number;
        line_with_min_number = string_number;
    }

    return _now_vector;
}


int getSum(std::vector< std::vector <double> > my_matrix)
{
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += my_matrix[line_with_min_number][i];
    }

    return sum;
}