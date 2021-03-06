//
//   Copyright 2014 Slack Technologies, Inc.
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.
//

#import <UIKit/UIKit.h>

@class SLKTextViewController;
@class SLKTextView;

typedef NS_ENUM(NSUInteger, SLKCounterStyle) {
    SLKCounterStyleNone,
    SLKCounterStyleSplit,
    SLKCounterStyleCountdown
};

/** @name A custom tool bar encapsulating messaging controls. */
@interface SLKTextInputbar : UIToolbar

/** A weak reference to the core view controller. */
@property (nonatomic, weak) SLKTextViewController *controller;

/** The centered text input view.
 The maximum number of lines is configured by default, to best fit each devices dimensions.
 For iPhone 4       (<=480pts): 4 lines
 For iPhone 5 & 6   (>=568pts): 6 lines
 For iPad           (>=768pts): 8 lines: 8 lines
 */
@property (nonatomic, strong) SLKTextView *textView;

/** The left action button action. */
@property (nonatomic, strong) UIButton *leftButton;

/** The right action button action. */
@property (nonatomic, strong) UIButton *rightButton;

/** YES if the right button should be hidden animatedly in case the text view has no text in it. Default is YES. */
@property (nonatomic, readwrite) BOOL autoHideRightButton;

/** The inner padding to use when laying out content in the view. Default is {5, 8, 5, 8}. */
@property (nonatomic, assign) UIEdgeInsets contentInset;

/** The maximum character count allowed. If larger than 0, a character count label will be displayed on top of the right button. Default is 0, which means infinite.*/
@property (nonatomic, readwrite) NSUInteger maxCharCount;

/** The character counter formatting. Ignored if maxCharCount is 0. Default is Split mode. */
@property (nonatomic, assign) SLKCounterStyle counterStyle;

/** YES if the maxmimum character count has been exceeded. */
@property (nonatomic, readonly) BOOL limitExceeded;


///------------------------------------------------
/// @name Text Editing
///------------------------------------------------

/** The view displayed on top of the below the text input bar when editing a message. */
@property (nonatomic, strong) UIView *accessoryView;

/** The title label displayed in the middle of the accessoryView. */
@property (nonatomic, strong) UILabel *editorTitle;

/** The 'cancel' button displayed left in the accessoryView. */
@property (nonatomic, strong) UIButton *editortLeftButton;

/** The 'accept' button displayed right in the accessoryView. */
@property (nonatomic, strong) UIButton *editortRightButton;

/** The accessory view's maximum height. Default is 38. */
@property (nonatomic, assign) CGFloat accessoryViewHeight;

/** A Boolean value indicating whether the control is in edit mode. */
@property (nonatomic, getter = isEditing) BOOL editing;

/** 
 Verifies if the text can be edited.
 
 @param text The text to be edited.
 @return YES if the text is editable.
 */
- (BOOL)canEditText:(NSString *)text;

/**
 Begins editing the text, by updating the 'editing' flag and the view constraints.
 */
- (void)beginTextEditing;

/**
 End editing the text, by updating the 'editing' flag and the view constraints.
 */
- (void)endTextEdition;

@end
