#ifndef ITERATOR_H
#define ITERATOR_H

#include <vector>

class ResponderComponent;

// ---------------------------------------------------------------------------
// ITERATOR PATTERN
// Participant: Iterator = Iterator, DFSIterator/BFSIterator/ActiveUnitIterator
// ---------------------------------------------------------------------------
class Iterator {
public:
    virtual ~Iterator() = default;
    virtual bool hasNext() const = 0;
    virtual ResponderComponent* next() = 0;
};


class DFSIterator : public Iterator {
public:
    explicit DFSIterator(ResponderComponent* root);
    bool hasNext() const override;
    ResponderComponent* next() override;

private:
    void collect(ResponderComponent* node);
    std::vector<ResponderComponent*> snapshot;
    std::size_t index = 0;
};


class BFSIterator : public Iterator {
public:
    explicit BFSIterator(ResponderComponent* root);
    bool hasNext() const override;
    ResponderComponent* next() override;

private:
    std::vector<ResponderComponent*> snapshot;
    std::size_t index = 0;
};

class ActiveUnitIterator : public Iterator {
public:
    explicit ActiveUnitIterator(ResponderComponent* root);
    bool hasNext() const override;
    ResponderComponent* next() override;

private:
    void collect(ResponderComponent* node, std::vector<ResponderComponent*>& all);
    std::vector<ResponderComponent*> snapshot;
    std::size_t index = 0;
};

#endif // ITERATOR_H
