TEST_F(ViewTargeterTest, DoesIntersectRect) {
  Widget widget;
  Widget::InitParams params = CreateParams(Widget::InitParams::TYPE_POPUP);
  params.ownership = views::Widget::InitParams::WIDGET_OWNS_NATIVE_WIDGET;
  params.bounds = gfx::Rect(0, 0, 650, 650);
  widget.Init(params);

  internal::RootView* root_view =
      static_cast<internal::RootView*>(widget.GetRootView());
  ViewTargeter* view_targeter = new ViewTargeter(root_view);
  root_view->SetEventTargeter(make_scoped_ptr(view_targeter));

  // The coordinates used for SetBounds() are in the parent coordinate space.
  TestingView v2;
  TestMaskedView v1, v3;
  v1.SetBounds(0, 0, 200, 200);
  v2.SetBounds(300, 0, 300, 300);
  v3.SetBounds(0, 0, 100, 100);
  root_view->AddChildView(&v1);
  root_view->AddChildView(&v2);
  v2.AddChildView(&v3);

  // The coordinates used below are in the local coordinate space of the
  // view that is passed in as an argument.

  // Hit tests against |v1|, which has a hit test mask.
  EXPECT_TRUE(v1.TestDoesIntersectRect(&v1, gfx::Rect(0, 0, 200, 200)));
  EXPECT_TRUE(v1.TestDoesIntersectRect(&v1, gfx::Rect(-10, -10, 110, 12)));
  EXPECT_TRUE(v1.TestDoesIntersectRect(&v1, gfx::Rect(112, 142, 1, 1)));
  EXPECT_FALSE(v1.TestDoesIntersectRect(&v1, gfx::Rect(0, 0, 20, 20)));
  EXPECT_FALSE(v1.TestDoesIntersectRect(&v1, gfx::Rect(-10, -10, 90, 12)));
  EXPECT_FALSE(v1.TestDoesIntersectRect(&v1, gfx::Rect(150, 49, 1, 1)));

  // Hit tests against |v2|, which does not have a hit test mask.
  EXPECT_TRUE(v2.TestDoesIntersectRect(&v2, gfx::Rect(0, 0, 200, 200)));
  EXPECT_TRUE(v2.TestDoesIntersectRect(&v2, gfx::Rect(-10, 250, 60, 60)));
  EXPECT_TRUE(v2.TestDoesIntersectRect(&v2, gfx::Rect(250, 250, 1, 1)));
  EXPECT_FALSE(v2.TestDoesIntersectRect(&v2, gfx::Rect(-10, 250, 7, 7)));
  EXPECT_FALSE(v2.TestDoesIntersectRect(&v2, gfx::Rect(-1, -1, 1, 1)));

  // Hit tests against |v3|, which has a hit test mask and is a child of |v2|.
  EXPECT_TRUE(v3.TestDoesIntersectRect(&v3, gfx::Rect(0, 0, 50, 50)));
  EXPECT_TRUE(v3.TestDoesIntersectRect(&v3, gfx::Rect(90, 90, 1, 1)));
  EXPECT_FALSE(v3.TestDoesIntersectRect(&v3, gfx::Rect(10, 125, 50, 50)));
  EXPECT_FALSE(v3.TestDoesIntersectRect(&v3, gfx::Rect(110, 110, 1, 1)));

  // Verify that hit-testing is performed correctly when using the
  // call-through function ViewTargeter::DoesIntersectRect().
  EXPECT_TRUE(view_targeter->DoesIntersectRect(root_view,
                                               gfx::Rect(0, 0, 50, 50)));
  EXPECT_FALSE(view_targeter->DoesIntersectRect(root_view,
                                                gfx::Rect(-20, -20, 10, 10)));
}