//https://leetcode.com/problems/employee-importance/

#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Employee info
class Employee {
   public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

class Solution {
   public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> data;
        for (int i = 0; i < employees.size(); ++i)
            data[employees[i]->id] = employees[i];
        int sum = 0;
        rec(data, sum, id);
        return sum;
    }

   private:
    void rec(unordered_map<int, Employee*>& employees, int& sum, int id) {
        sum += employees[id]->importance;
        for (int idx = 0; idx < employees[id]->subordinates.size(); ++idx)
            rec(employees, sum, employees[id]->subordinates[idx]);
    }
};