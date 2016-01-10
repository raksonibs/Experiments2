package example;

import java.io.IOException;
import java.text.DecimalFormat;

import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class webApp extends HttpServlet {
  private Cookie createCookie(String cookieName, String cookieValue) {
      Cookie cookie = new Cookie(cookieName, cookieValue);
      cookie.setPath("/");
      cookie.setMaxAge(1000000);
      cookie.setHttpOnly(true);
      cookie.setSecure(true);
      return cookie;
  }
  @Override
  protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
    System.out.println("helloworld!");
    System.out.println(req.getRemoteAddr());
    System.out.println(req.getRemotePort());
    System.out.println(req.getProtocol());
    System.out.println(req.getMethod());
    System.out.println(req.getQueryString());
    System.out.println(req.getParameter("name"));
    System.out.println(req.getContextPath());
    System.out.println(req.getRequestURL());
    System.out.println(req.getServletPath());
    
    Double principle;
    Double period;
    Double interest;
    
    principle = Double.parseDouble(this.getServletContext().getInitParameter("principle"));
    period = Double.parseDouble(this.getServletContext().getInitParameter("period"));
    interest = Double.parseDouble(this.getServletContext().getInitParameter("interest"));
    
    if (req.getParameter("principle") != null) principle = Double.parseDouble(req.getParameter("principle"));
    if (req.getParameter("period") != null) period = Double.parseDouble(req.getParameter("period"));
    if (req.getParameter("interest") != null) interest = Double.parseDouble(req.getParameter("interest"));
    double compondThis = (1 + (interest/12));
    double dividePrincipleBy = 1 - (Math.pow(compondThis, (-1*period)));
    
    double valueReturned = (interest/12) * principle/dividePrincipleBy;
    
    System.out.println(req.getPathTranslated());
    System.out.println(req.getPathInfo());
    
    System.out.println(this.getServletContext().getContextPath());
    
    System.out.println("Approaching Redirect");
    DecimalFormat df = new DecimalFormat("#.##");
    
    Cookie[] cookies = req.getCookies();
    
    Cookie myCookie =
          new Cookie("principle", principle.toString());
          resp.addCookie(myCookie);
          
          Cookie myCookie2 =
              new Cookie("period", period.toString());
              resp.addCookie(myCookie);
    
    if (req.getPathInfo() != null && req.getPathInfo().equals("/YorkBank")) {
      System.out.println("Redirecting");
      String  url = this.getServletContext().getContextPath() + "/Start";
      resp.sendRedirect(url);
    } else {
      System.out.println("Not Redirecting");
      resp.getWriter().println("Testing Tomcat");
      resp.getWriter().println("Monthly installments of: " + df.format(valueReturned));
    }
  
  }
  
}
