struct GraphNode {
    int label;
    vector<GraphNode*> neighbours;
    GraphNode(int x) : label(x) {};
};

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<GraphNode*> graph;
        vector<int> degree;
        for (int i = 0; i < numCourses; i++) {
            graph.push_back(new GraphNode(i));
            degree.push_back(0);
        }
        for (int i = 0; i < prerequisites.size(); i++) {
            GraphNode *begin = graph[prerequisites[i].second];
            GraphNode *end = graph[prerequisites[i].first];
            begin->neighbours.push_back(end);
            degree[end->label] += 1;
        }
        
        queue<GraphNode*> q;
        vector<GraphNode*> zeros;
        for (int i = 0; i < numCourses; i++) {
            if (degree[i] == 0) {
                q.push(graph[i]);
                zeros.push_back(graph[i]);
            }
        }
        while (!q.empty()) {
            GraphNode *node = q.front();
            q.pop();
            for (int i = 0; i < node->neighbours.size(); i++) {
                degree[node->neighbours[i]->label] -= 1;
                if (degree[node->neighbours[i]->label] == 0) {
                    q.push(node->neighbours[i]);
                    zeros.push_back(node->neighbours[i]);
                }
            }
        }
        if (zeros.size() == numCourses) {
            return true;
        }
        return false;
    }
};
