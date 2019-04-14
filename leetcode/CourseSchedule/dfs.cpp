// Time Limit Exceeded
struct GraphNode {
    int label;
    vector<GraphNode*> neighbours;
    GraphNode(int x) : label(x) {};
};

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<GraphNode*> graph;
        vector<int> visited;
        for (int i = 0; i < numCourses; i++) {
            graph.push_back(new GraphNode(i));
            visited.push_back(-1);
        }
        for (int i = 0; i < prerequisites.size(); i++) {
            GraphNode *begin = graph[prerequisites[i].second];
            GraphNode *end = graph[prerequisites[i].first];
            begin->neighbours.push_back(end);
        }
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] != -1) {
                continue;
            }
            if (!dfs(graph[i], visited)) {
                return false;
            }
        }
        return true;
    }
private:
    bool dfs(GraphNode* node, vector<int> visited) {
        visited[node->label] = 0;
        for (int i = 0; i < node->neighbours.size(); i++) {
            if (visited[node->neighbours[i]->label] == -1) {
                if (!dfs(node->neighbours[i], visited)) {
                    return false;
                }
            } else if (visited[node->neighbours[i]->label] == 0) {
                return false;
            }
        }
        visited[node->label] = 1;
        return true;
    }
};
