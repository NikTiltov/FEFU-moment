#include <fstream>
#include <queue>

typedef std::queue<std::pair<size_t, size_t>> qpss;

struct user {
    bool contacts[100]{};
    bool received[100]{};
    bool did_send = false;
    size_t counter = 0;
};

void day(qpss &q, user *u, size_t at);
void night(qpss &q, user *u);

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    user users[100]{};
    qpss messages;

    size_t amount; fin >> amount;
    for(size_t i = 0; i != amount; ++i) {
        size_t contacts; fin >> contacts;
        for(size_t j = 0; j != contacts; ++j) {
            int pos; fin >> pos;
            users[i].contacts[pos - 1] = true;
        }
    }

    day(messages, users, 0);
    while(!messages.empty()) {
        night(messages, users);
    }

    for(size_t i = 0; i != amount; ++i) {
        fout << users[i].counter << " ";
    }
}

void day(qpss &q, user *u, size_t at) {
    if(u[at].did_send) return;
    
    for(size_t i = 0; i != 100; ++i) {
        if(u[at].contacts[i] && !u[at].received[i]) {
            q.emplace(i, at);
        }
    }
}

void night(qpss &q, user *u) {
    bool sent_to[100]{};
    while(!q.empty()) {
        auto pos = q.front();
        u[pos.first].counter++;
        u[pos.first].received[pos.second] = true;
        u[pos.second].did_send = true;
        sent_to[pos.first] = true;
        q.pop();
    }

    for(size_t i = 0; i != 100; ++i) {
        if(sent_to[i]) day(q, u, i);
    }
}
