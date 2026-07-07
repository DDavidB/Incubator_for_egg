from fpdf import FPDF

content = [
    ("title", "Egg Incubator Project Initiation Document"),
    ("heading", "1. Project Overview"),
    ("paragraph", "This project is intended to develop a reliable egg incubator system for chicken eggs using an Arduino-based controller and supporting hardware. The system will maintain optimal temperature and humidity levels inside the incubator while providing real-time status feedback and hatch detection alerts."),
    ("heading", "2. Project Objectives"),
    ("list", [
        "Deliver a stable and dependable chicken egg incubation system.",
        "Maintain precise temperature and humidity control within the incubator.",
        "Display temperature and humidity readings in real time on a digital screen.",
        "Detect egg movement during hatching and trigger an audible alert.",
        "Create an educational platform for understanding electronic control systems."
    ]),
    ("heading", "3. Scope"),
    ("paragraph", "The scope of this project includes hardware selection, wiring design, control algorithm definition, display interface design, hatch detection logic, and alarm notification. The project does not include production-level industrial enclosure design, cloud connectivity, or remote monitoring at this stage."),
    ("heading", "4. Functional Requirements"),
    ("list", [
        "Measure incubator temperature and humidity continuously.",
        "Activate heating when temperature falls below the defined threshold.",
        "Deactivate heating when temperature reaches or exceeds the setpoint.",
        "Control fan operation to support humidity and ventilation management.",
        "Show current temperature and humidity values on the LCD display.",
        "Detect significant motion from the egg using an accelerometer sensor.",
        "Trigger an audible alarm when hatch movement is detected."
    ]),
    ("heading", "5. Non-Functional Requirements"),
    ("list", [
        "The system must operate continuously for the full incubation cycle without manual intervention.",
        "Control logic should be simple, maintainable, and safe for consumer-grade hardware.",
        "Use standard Arduino-compatible components to simplify implementation and maintenance.",
        "Provide sufficient documentation for wiring, assembly, and operation."
    ]),
    ("heading", "6. Hardware Components"),
    ("list", [
        "Arduino board (for example, Arduino Uno).",
        "DHT22 temperature and humidity sensor.",
        "Ceramic heating element.",
        "Relay module for heater control.",
        "Small fan for ventilation.",
        "Relay module for fan control.",
        "Breadboard and connection wires.",
        "Power supply or adapter for Arduino.",
        "16x2 LCD display with I2C interface.",
        "Inertial sensor such as ADXL345 or MPU6050 accelerometer.",
        "Piezo buzzer or small speaker for alarm output."
    ]),
    ("heading", "7. Hardware Interfaces and Connections"),
    ("paragraph", "The following hardware connections define the expected control and sensor interfaces for the incubator system."),
    ("subheading", "DHT22 Temperature and Humidity Sensor"),
    ("list", [
        "VCC to Arduino 5V.",
        "GND to Arduino GND.",
        "DATA to Arduino digital pin 2."
    ]),
    ("subheading", "Heater Relay Module"),
    ("list", [
        "VCC to Arduino 5V.",
        "GND to Arduino GND.",
        "IN to Arduino digital pin 3.",
        "COM to the heater live power line.",
        "NO to the heater element."
    ]),
    ("subheading", "Fan Relay Module"),
    ("list", [
        "VCC to Arduino 5V.",
        "GND to Arduino GND.",
        "IN to Arduino digital pin 4.",
        "COM to the fan live power line.",
        "NO to the fan."
    ]),
    ("subheading", "Power Supply"),
    ("paragraph", "The Arduino should be powered either from a dedicated adapter connected to the Arduino power input or a suitable battery connected to VIN and GND. All sensor and controller grounds must share a common reference.") ,
    ("subheading", "16x2 I2C LCD Display"),
    ("list", [
        "VCC to Arduino 5V.",
        "GND to Arduino GND.",
        "SDA to Arduino A4.",
        "SCL to Arduino A5."
    ]),
    ("subheading", "Accelerometer Sensor (e.g. MPU6050)"),
    ("list", [
        "VCC to Arduino 3.3V.",
        "GND to Arduino GND.",
        "SDA to Arduino A4.",
        "SCL to Arduino A5."
    ]),
    ("subheading", "Buzzer"),
    ("list", [
        "Positive to Arduino digital pin 5.",
        "Negative to Arduino GND."
    ]),
    ("heading", "8. Implementation Notes"),
    ("paragraph", "The system implementation should keep code structure modular and hardware-agnostic where possible. Control logic should separate sensor reading, decision rules, actuator control, display updates, and alarm handling. The document intentionally omits source code samples and focuses on the software development planning and system design."),
    ("heading", "9. Assumptions and Constraints"),
    ("list", [
        "The incubator hardware will be assembled using Arduino-compatible modules.",
        "The temperature and humidity sensor is accurate enough for basic incubation control.",
        "No advanced networking or cloud integration is required for the initial version.",
        "Safety measures such as proper external power isolation for heater and fan circuits are mandatory."
    ]),
    ("heading", "10. Success Criteria"),
    ("list", [
        "The incubator maintains temperature and humidity within the target range during operation.",
        "The LCD displays accurate, real-time environmental data.",
        "The system reliably detects hatch movement and sounds an audible alert.",
        "The solution remains easy to assemble, understand, and maintain."
    ]),
    ("heading", "11. Recommended Next Steps"),
    ("list", [
        "Develop the Arduino firmware using the defined sensor and actuator interfaces.",
        "Prototype the wiring on a breadboard and validate sensor accuracy.",
        "Implement safety checks for heater and fan power circuits.",
        "Test the hatch detection algorithm with sample motion data." 
    ])
]

pdf = FPDF()
pdf.add_page()
pdf.set_auto_page_break(auto=True, margin=15)
pdf.set_font('Arial', 'B', 18)
pdf.cell(0, 10, content[0][1], ln=True, align='C')
pdf.ln(5)
font_size = 12
for item in content[1:]:
    kind, value = item
    if kind == 'heading':
        pdf.set_font('Arial', 'B', 14)
        pdf.cell(0, 8, value, ln=True)
        pdf.ln(1)
        pdf.set_font('Arial', '', font_size)
    elif kind == 'subheading':
        pdf.set_font('Arial', 'B', 12)
        pdf.cell(0, 7, value, ln=True)
        pdf.set_font('Arial', '', font_size)
    elif kind == 'paragraph':
        pdf.multi_cell(0, 6, value)
        pdf.ln(2)
    elif kind == 'list':
        for line in value:
            pdf.multi_cell(0, 6, f"- {line}")
        pdf.ln(2)

pdf.output('Project_Initiation_Document.pdf')
print('Generated Project_Initiation_Document.pdf')