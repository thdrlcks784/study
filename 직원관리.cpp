#include <iostream>
using namespace std;
class EmployeeList {
        private:
                string information[100][3];
                int count;
        public :
                EmployeeList() {}
                EmployeeList(int C) {
                        count = 0;
                        information[0][0] = "나태희";
                        information[0][1] = "부장";
                        information[0][2] = "010-5228-7889";
                        information[1][0] = "유현빈";
                        information[1][1] = "차장";
                        information[1][2] = "010-5211-1472";
                        information[2][0] = "나원빈";
                        information[2][1] = "과장";
                        information[2][2] = "010-1235-8765";
                        information[3][0] = "이나라";
                        information[3][1] = "대리";
                        information[3][2] = "010-5210-1234";
                        information[4][0] = "고수영";
                        information[4][1] = "직원";
                        information[4][2] = "010-8282-3483";
                        information[5][0] = "소지법";
                        information[5][1] = "직원";
                        information[5][2] = "010-2049-9938";
                        information[6][0] = "김인철";
                        information[6][1] = "과장";
                        information[6][2] = "010-3784-5129";
                        information[7][0] = "성기수";
                        information[7][1] = "부장";
                        information[7][2] = "010-2351-5478";
                        information[8][0] = "한대웅";
                        information[8][1] = "직원";
                        information[8][2] = "010-0127-7326";
                        information[9][0] = "정준하";
                        information[9][1] = "차장";
                        information[9][2] = "010-1679-9936";
                        count = 10;
                }
                void inputNewMember(string name, string position, string number) {
                        information[count][0] = name;
                        information[count][1] = position;
                        information[count][2] = number;
                        count = count + 1;
                }
                void deleteMember(string name) {
                        int i,del_num = 0;
                        string buf[3];
                        for (i = 0; i < 100; i++) {
                                if (information[i][0] == name) {
                                        del_num = i;
                                        break;
                                }

                        }
                        if (i == 100) { cout << "잘못된 이름을 입력했습니다." << endl; return; }
                        for (del_num; del_num < count; del_num++) {
                                information[del_num][0] = information[del_num + 1][0];
                                information[del_num][1] = information[del_num + 1][1];
                                information[del_num][2] = information[del_num + 1][2];

                        }
                        information[count][0] = '\0';
                        information[count][1] = '\0';
                        information[count][2] = '\0';
                        count = count - 1;
                }
                string getName(int index) {
                        return information[index][0];
                }
                int getIndex(string name) {
                        int rt_index = 0;
                        for (int i = 0; i < 100; i++) {
                                if (information[i][0] == name) {
                                        rt_index = i;
                                        break;
                                }
                        }
                        return rt_index;
                }

                string getPosition(string name) {
                        int rt_index;
                        for (int i = 0; i < 100; i++) {
                                if (information[i][0] == name) {
                                        rt_index = i;
                                        break;
                                }
                        }
                        return information[rt_index][1];
                }
                int returnCount() { return count; }
                void showData() {
                        cout << "index_num\tname\tposition\tnumber" << endl;
                        for (int i = 0; i < count; i++) {
                                cout << i << "\t\t" << information[i][0] << "\t" << information[i][1] << "\t\t" << information[i][2] << endl;
                        }
                }

};
class Attendance :EmployeeList {
        private:
                int attendance[31][100];
                int overtime[100];  //날짜를 위해 배열을 추가함

        public :
                Attendance() {}
                Attendance(int A) {
                        memset(overtime, A, sizeof(overtime));
                        memset(attendance, A, sizeof(attendance));
                }
                int getOvertimehours(int index) {
                        return overtime[index];
                }
                void setOvertimehours(int index, int over_t) {
                        if (over_t > 12 || over_t < 0) { cout << "잘못된 입력입니다. 야근시간은 0~12 시간 사이만을 입력할 수 있습니다." << endl; return; }
                        overtime[index] = overtime[index]+ over_t;
                }
                void setMemberAttendance(int date,int index) {
                        attendance[date][index] = 1;    //내용이 0일경우 결근 1일경우 출석
                }

                void showData() {
                        cout << "index_num\tovertime" << endl;
                        for (int i = 0; i < returnCount() + 1; i++) {
                                cout << i << "\t" << overtime[i] << endl;
                        }
                }
};
class Salary :EmployeeList,Attendance{
        private :
                string name, position;
                int overtime, finalBenefit,bonus;
                double  pos_pay[5] = { 500 * 1.2 , 400 * 1.15 , 300 * 1.1,200 * 1.07 , 150 * 1.05 };
        public:
                Salary(string _name, string _position, int _overtime){    //최종급여  : 기본 급여 + (기본 급여 x 직책 수당) + 야근 수당 + 보너스 금액.
                        name = _name;
                        position = _position;
                        overtime = _overtime;
                }
                Salary(int _bonus) { bonus = _bonus; }

                int returnSalary(string p) {
                        if (p == "부장") { return (int)pos_pay[0]; }
                        else if (p == "차장") { return (int)pos_pay[1]; }
                        else if (p == "과장") { return (int)pos_pay[2]; }
                        else if (p == "대리") { return (int)pos_pay[3]; }
                        else if (p == "직원") { return (int)pos_pay[4]; }
                }
                const Salary operator+(Salary& S)const {
                        EmployeeList E;
                        Attendance A;
                        S.finalBenefit = S.returnSalary(position) + overtime +S.bonus;
                        return S;
                }
                int retrunBenefit() {
                        return finalBenefit;
                }
                void showData(){
                        cout << "index_num\tname\tposition\tovertime\tfinalBenefit" << endl;
                        for (int i = 0; i < EmployeeList::returnCount() + 1; i++) {
                                cout << i << "\t" << EmployeeList::getName(i) << "\t" << EmployeeList::getPosition(EmployeeList::getName(i)) << "\t" << getOvertimehours(i)<<"\t"<<finalBenefit << endl;
                        }
                }

};
int main() {
        Attendance A(0);
        EmployeeList E(0);
        char fun;
        int index, date, overtime,bonus;
        string name, position, number;
        while (1) {
                E.showData();
                cout << "1.직원등록  2. 직원삭제  3. 출근 및 야근시간 관리 4. 직원 급여 계산 5. 종료" << endl << "숫자를 입력하시오 : " << endl;
                cin >> fun;
                switch (fun) {
                case '1':
                        cout << "등록할 직원의 이름을 입력하시오 :" << endl;
                        cin >> name;
                        cout << "등록할 직원의 직급을 입력하시오 : " << endl;
                        cin >> position;
                        cout << "등록할 직원의 전화번호를 입력하시오 :" << endl;
                        cin >> number;
                        E.inputNewMember(name, position, number);
                        break;
                case '2':
                        cout << "삭제할 직원의 이름을 입력하시오 : " << endl;
                        cin >> name;
                        E.deleteMember(name);
                        break;
                case '3':
                        cout << "본인의 인덱스 번호를 입력하시오 :" << endl;
                        cin >> index;
                        cout << "출근한 날짜를 입력하시오 : " << endl;
                        cin >> date;
                        cout << "당일 야근시간을 입력하시오 : " << endl;
                        cin >> overtime;
                        A.setOvertimehours(index, overtime);
                        A.setMemberAttendance(date, index);
                        cout << E.getName(index) << "님의 " << date << " 일 출근하였으며 당일 야근 시간은 " << overtime << " 시간이고 누적 야근시간은 " << A.getOvertimehours(index) << " 시간입니다." << endl;
                        break;
                case '4': {
                        cout << "본인의 인덱스 번호를 입력하시오";
                        cin >> index;
                        cout << E.getName(index) << "님의 보너스를 입력하시오 :" << endl;
                        cin >> bonus;
                        if (bonus > 100 || bonus < 0) { cout << "잘못된 입력입니다. 보너스는 0~100사이의 값을 입력할 수 있습니다." << endl; break; }
                        Salary S1(E.getName(index), E.getPosition(E.getName(index)), A.getOvertimehours(index));
                        Salary S2(bonus);
                        Salary S3 = S1.operator+(S2);
                        int benefit = S3.retrunBenefit();
                        cout << E.getName(index)<<"님의 급여 : "<<benefit << endl;
                        break;
                }
                case '5':
                        exit(0);
                }
        }
}
