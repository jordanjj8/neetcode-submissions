class Solution {
public:
    unordered_set<int> taking;
    vector<vector<int>> adj;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /*
        ex: 0, 1
        map : {0: 1}
        
        ex: [0, 1] [1,0]
        map: {0: 1, 1: 0}

        to find whether we can finish, we need to find a valid path (DAG)
        that has size of numCourse 
        
        DFS 
        keep a taking hashmap while iterating
        if we see a class we are currently taking (dfs path), then we have found an invalid path
        resulting in false
        in order to know what we are iterating through, we need to create an adjacency list 
        to actually traverse through
        output: DAG (directed acylic graph)
    
        */
        for (int c=0; c <numCourses; c++) {
            adj.push_back({});
        }
        // populate the adjacency list with prereqs
        for (auto courses: prerequisites) {
            int course = courses[0];
            int pre = courses[1];
            adj[course].push_back(pre);
        }

        // recursive dfs to find cycles with all the required number of courses
        for (int c=0; c < numCourses; c++) {
            if (!dfs(c)) {
                return false;
            }
        }
        // if dfs was able to traverse through adjacent list without cycles, return true
        return true;
    }

    bool dfs(int course) {
        // if we are taking the course already, return false
        if (taking.count(course)) {
            return false;
        }
        // mark course as taking
        taking.insert(course);
        // look through the adjacency list of course
        for (int i=0; i < adj[course].size(); i++) {
            if (!dfs(adj[course][i])) {
                return false;
            }
        }
        taking.erase(course);

        return true;
    }
};
