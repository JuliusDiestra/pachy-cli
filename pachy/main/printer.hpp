#ifndef MAIN_PRINTER_HPP_
#define MAIN_PRINTER_HPP_

namespace pachy {

class Printer {
  public:
    Printer() = default;
    void help() const;
    void version() const;
};

}  // namespace pachy

#endif  // MAIN_PRINTER_HPP_
