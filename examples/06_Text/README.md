## Pitfalls
Due to the caching system of the glyphs, the order of the called functions is important, unlike all other Qube2D objects.
First all the functions concerning the font or text-style should be called before actually setting the text via 'setText'.

```c++
// Example of calling order
text.setFont(font);
text.setTextSize(32);
text.setOutlineWidth(2.f);
text.setText(U"My text!", Qube2D::TextStyle::Outline);
```

All the transformations, like 'setPosition', 'setColor' or 'setRotation' can still be applied anywhere in the code.
