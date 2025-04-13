#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <vector>
#include <memory>

// Forward declaration để tránh phụ thuộc vòng tròn với lớp Board
class Board;

/**
 * @struct Position
 * @brief Đại diện cho một ô trên bàn cờ, bao gồm thông tin về hàng và cột.
 * 
 * Cấu trúc này hỗ trợ các phương thức chuyển đổi giữa tọa độ và ký hiệu cờ vua.
 */
struct Position {
    int row;    ///< Chỉ số hàng (0 - 7), tương ứng với 8 - 1 trong ký hiệu cờ vua.
    int column; ///< Chỉ số cột (0 - 7), tương ứng với a - h trong ký hiệu cờ vua.

    /**
     * @brief Khởi tạo một đối tượng Position với giá trị cột và hàng.
     * @param col Cột (0 - 7).
     * @param r Hàng (0 - 7).
     */
    Position(int col = 0, int r = 0) : column(col), row(r) {}

    /**
     * @brief Toán tử so sánh để kiểm tra xem hai vị trí có bằng nhau không.
     * @param other Vị trí cần so sánh.
     * @return True nếu hai vị trí bằng nhau, ngược lại false.
     */
    bool operator==(const Position& other) const;

    /**
     * @brief Chuyển đổi một vị trí sang ký hiệu cờ vua (ví dụ: từ (0,0) thành "a8").
     * @return Ký hiệu cờ vua tương ứng với vị trí hiện tại.
     */
    std::string toChessNotation() const;

    /**
     * @brief Tạo một đối tượng Position từ ký hiệu cờ vua.
     * @param notation Ký hiệu cờ vua cần chuyển đổi (ví dụ: "e4").
     * @return Vị trí tương ứng với ký hiệu cờ vua, hoặc (-1, -1) nếu ký hiệu không hợp lệ.
     */
    static Position fromChessNotation(const std::string& notation);
};

/**
 * @class MovementStrategy
 * @brief Interface xác định các chiến lược di chuyển của quân cờ.
 * 
 * Các lớp con của MovementStrategy sẽ định nghĩa cách di chuyển cụ thể của từng quân cờ.
 */
class MovementStrategy {
public:
    virtual ~MovementStrategy() = default;

    /**
     * @brief Kiểm tra tính hợp lệ của một nước đi từ vị trí `from` tới vị trí `to`.
     * @param from Vị trí xuất phát.
     * @param to Vị trí đích.
     * @param board Bàn cờ hiện tại.
     * @return True nếu nước đi hợp lệ, ngược lại false.
     */
    virtual bool isValidMove(const Position& from, const Position& to, const Board& board) const = 0;

    /**
     * @brief Lấy danh sách các vị trí có thể di chuyển đến từ vị trí `from` trên bàn cờ hiện tại.
     * @param from Vị trí xuất phát.
     * @param board Bàn cờ hiện tại.
     * @return Danh sách các vị trí hợp lệ có thể di chuyển đến.
     */
    virtual std::vector<Position> getPossibleMoves(const Position& from, const Board& board) const = 0;
};

/**
 * @enum PieceColor
 * @brief Định nghĩa các màu sắc của quân cờ (trắng và đen).
 */
enum class PieceColor {
    WHITE, ///< Quân cờ màu trắng.
    BLACK  ///< Quân cờ màu đen.
};

#endif // PIECE_H
