class Solution {
public:
    // taking: courses currently on active DFS stack/path
    // tells us when we found a cycle
    unordered_set<int> taking;
    // adj: course -> list of prereqs
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
        // In case adj is not clear
        adj.clear();

        //  Build adjacency list
        for (int c=0; c <numCourses; c++) {
            adj.push_back({});
        }
        // populate the adjacency list with prereqs
        for (auto courses: prerequisites) {
            int course = courses[0];
            int pre = courses[1];
            adj[course].push_back(pre);
        }

        // start DFS from every course to cover any disconnected courses
        for (int c=0; c < numCourses; c++) {
            if (!dfs(c)) {
                // found cycle
                return false;
            }
        }
        // if dfs was able to traverse through adjacent list without cycles, return true
        return true;
    }

    bool dfs(int course) {
        // if course already on current recursive stack/path
        if (taking.count(course)) {
            // cycle found
            return false;
        }
        // mark course as taking
        taking.insert(course);

        // recursively explore the adjacency list
        for (int i=0; i < adj[course].size(); i++) {
            if (!dfs(adj[course][i])) {
                return false;
            }
        }
        // done taking this course, remove from path/stack
        taking.erase(course);

        return true;
    }
};