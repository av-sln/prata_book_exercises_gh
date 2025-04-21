// queuetp.h -- шаблонный класс QueueTP

#ifndef QUEUETP_H_
#define QUEUETP_H_

template<typename Type>
class QueueTP {
private:
  struct Node {
    Type item_;
    Node* next_;
  };
  enum {Q_SIZE = 10};
  Node* front_;
  Node* rear_;
  int items_;
  const int qsize_;
  
  // Упреждающее объявление для предотвращения открытого копирования
  QueueTP(const QueueTP& r_q) : qsize_(0) {}
  QueueTP& operator=(const QueueTP& r_q) { return *this; }

public:
  QueueTP(int qs = Q_SIZE);
  ~QueueTP();
  // Пуста ли очередь
  bool QueueTP::isempty() const;
  // Полна ли очередь
  bool QueueTP::isfull() const;
  // Количество элементов в очереди
  int QueueTP::queuecount() const;
  // Добавление элемента в конец очереди
  bool QueueTP::enqueue(const Type& item);
  // Удаление элемента из начала очереди
  bool QueueTP::dequeue(Type& item);
};

// Методы класса QueueTP
template<typename Type>
QueueTP<Type>::QueueTP(int qs) : qsize_(qs)
{
  front_ = rear_ = nullptr;
  items_ = 0;
}

template<typename Type>
QueueTP<Type>::~QueueTP()
{
  Node* temp;
  while (front_) {
    temp = front_;
    front_ = front_->next_;
    delete temp;
  }
}

template<typename Type>
bool QueueTP<Type>::isempty() const
{
  return items_ == 0;
}

template<typename Type>
bool QueueTP<Type>::isfull() const
{
  return items_ == qsize_;
}

template<typename Type>
int QueueTP<Type>::queuecount() const
{
  return items_;
}

template<typename Type>
bool QueueTP<Type>::enqueue(const Type& item)
{
  if (isfull())
    return false;
  Node* add = new Node;
  add->item_ = item;
  add->next_ = nullptr;
  items_++;
  if (!front_)
    front_ = add;
  else
    rear_->next_ = add;
  rear_ = add;
  return true;
}

template<typename Type>
bool QueueTP<Type>::dequeue(Type& item)
{
  if (!front_)
    return false;
  item = front_->item_;
  items_--;
  Node* temp = front_;
  front_ = front_->next_;
  delete temp;
  if (items_ == 0)
    rear_ = nullptr;
  return true;
}

#endif // queuetp.h