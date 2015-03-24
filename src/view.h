#include <map>
#include <vector>

class Vim;

@class NSImage;

@interface VimView : NSView {
    Vim *mVim;
    NSImage *mCanvas;
    int mXCells;
    int mYCells;
    bool mInsertMode;
    NSColor *mBackgroundColor;
    NSColor *mForegroundColor;
    NSMutableDictionary *mTextAttrs;
    std::vector<NSEvent *>mKeyQueue;
    int mWaitAck;
    NSSize mCharSize;
    NSFont *mFont;
    CGRect mCellScrollRect;
}

- (void)requestResize:(CGSize)cellSize;

- (id)initWithFrame:(NSRect)frame vim:(Vim *)vim;

- (NSRect)viewRectFromCellRect:(NSRect)cellRect;
- (CGSize)viewSizeFromCellSize:(CGSize)cellSize;
- (CGSize)cellSizeInsideViewSize:(CGSize)viewSize;

@end