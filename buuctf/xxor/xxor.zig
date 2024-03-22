const std = @import("std");
const print = std.debug.print;
const key = [_]i32{ 0x00000002, 0x00000002, 0x00000003, 0x00000004 };
var enc = [_]i32{
    -0x20b71082,
    0x20caacf4,
    -520941611,
    1548802262,
    -1642340819,
    -0x7b0cfbe0,
};
pub fn main() !void {
    var i: usize = 0;
    while (i < 6) {
        try decrypt(&enc[i], &enc[i + 1]);
        i += 2;
    }
}

fn decrypt(ii1: *i32, ii2: *i32) !void {
    var input1: i32 = ii1.*;
    var input2: i32 = ii2.*;
    const sum__ = @mulWithOverflow(@as(i32, 0x458bcd42), @as(i32, 64));
    var sum_: i32 = sum__[0];
    var i: i32 = 63;
    while (i >= 0) {
        input2 = input2 - (key[3] + (input1 >> 9) ^ @mulWithOverflow(input1, @as(i32, 0x40))[0] + key[2] ^ sum_ + input1 + 0x14 ^ 0x10);
        input1 = input1 - (key[1] + (input2 >> 9) ^ @mulWithOverflow(input2, @as(i32, 0x40))[0] + key[0] ^ sum_ + input2 + 0xb ^ 0x20);
        sum_ = @addWithOverflow(@as(i32, -0x458bcd42), sum_)[0];
        i -= 1;
    }
    ii1.* = input1;
    ii2.* = input2;
}
