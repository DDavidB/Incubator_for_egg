# Incubator_for_egg

פרויקט לבניית בינה מלאכותית (בקר) למערכת אינקובציה עם בקרה על טמפרטורה ולחות.

הפרויקט כולל:
- ספריית C++ `incubator_core` עם בקרים לחימום ולחות
- בדיקות יחידה באמצעות GoogleTest
- CMake כסביבת בנייה

## איך לבנות

בחלון PowerShell בתוך תיקיית הפרויקט:

```powershell
cd C:\Users\david\Incubator_for_egg
cmake -S . -B build
cmake --build build --config Debug
```

## איך להריץ את הבדיקות

```powershell
cd C:\Users\david\Incubator_for_egg
ctest --test-dir build --output-on-failure
```

## תיעוד חיבור חוטים

קובץ ההסבר על חיבורים והרצה נמצא ב-`WIRING_AND_USE.txt`.
