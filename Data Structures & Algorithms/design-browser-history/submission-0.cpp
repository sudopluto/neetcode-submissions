class BrowserHistory {
    class historyRec;

    struct historyRec {
        std::string m_url{};
        historyRec* m_prevPage{nullptr};
        historyRec* m_nextPage{nullptr};

        historyRec(std::string url) : m_url{url} {}
        historyRec(std::string url, historyRec* prev) 
            : m_url{url}, m_prevPage{prev} {}
    };

    historyRec* m_homepage{nullptr};
    historyRec* m_tail{nullptr};
    historyRec* m_curr{nullptr};

    void clearForwardHistory() {
        while(m_tail != m_curr) {
            historyRec* toDelete = m_tail;
            m_tail = m_tail->m_prevPage;
            m_tail->m_nextPage = nullptr;
            delete toDelete;
        }
        return; 
    }

public:
    BrowserHistory(std::string homepage) {
        m_homepage = new historyRec(homepage);
        m_tail = m_homepage;
        m_curr = m_homepage;
    }
    
    void visit(string url) {
        clearForwardHistory();
        m_tail->m_nextPage = new historyRec(url, m_tail);
        m_tail = m_tail->m_nextPage;
        m_curr = m_tail;
    }
    
    string back(int steps) {
        while((m_curr != m_homepage) && (steps > 0)) {
            m_curr = m_curr->m_prevPage;
            --steps;
        }
        return m_curr->m_url;
    }
    
    string forward(int steps) {
        while((m_curr != m_tail) && (steps > 0)) {
            m_curr = m_curr->m_nextPage;
            --steps;
        }
        return m_curr->m_url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */